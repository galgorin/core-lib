//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/prerequisites.c";
#include <mtypes.h>

#define Speech "[0;33m"
#define Desc "[0;36m"
#define End "[0m"
#define Stat(x) sprintf("[0;34m[%s][0m", x)
#define Action(x) sprintf("[0;31m[%s][0m", x)

private string MaterialAttributes = "lib/modules/materialAttributes.c";
private int ignoreTalk = 0;
private int SetupCompleted = 0;

private mapping responseKeys = ([]);
private mapping topics = ([
    //    "key": ([
    //        "template": "Hi there!",
    //        "is repeatable": 1, // if this doesn't exist, it's not repeatable
    //        "responses": ([
    //            "key": ([
    //                "template": "some text",
    //                "criteria": ([
    //                    "stat": "statName";"GreaterThan|LessThan";"value",
    //                    "guild": "is|isNot";"value",
    //                    "function": "object";"method",
    //                    "state": "a state",
    //                    "object present": "object"
    //                ]),
    //                "npc response": "key",
    //                "delegate": "other";"key", //trigger comment from other NPC
    //                "trigger": "event" // send 'event' to stateMachine
    //            ])
    //        ]),
    //        "criteria": ([ /* same structure as responses criteria */ ]),
    //        "trigger": "event"; "name" // send 'name' event to owning stateMachine
    //                          "method"; "name" // execute 'name' method on this NPC object
    //    ])
]);

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{

}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        if (!SetupCompleted)
        {
            Setup();
            SetupCompleted = 1;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addTopic(string id, string template)
{
    if (!member(topics, id))
    {
        topics[id] = ([
            "template": template
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addRepeatableTopic(string id, string template)
{
    addTopic(id, template);
    topics[id]["is repeatable"] = 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addTopicPrerequisite(string id, mapping prerequisite)
{
    if (member(topics, id))
    {
        addPrerequisite(id, prerequisite, id);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addTopicEvent(string id, string event)
{
    if (member(topics, id))
    {
        topics[id]["event"] = event;
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addTopicTrigger(string id, string event)
{
    if (member(topics, id))
    {
        topics[id]["trigger"] = event;
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addResponse(string id, string selection, string template)
{
    if (member(topics, id))
    {
        if (!member(topics[id], "responses"))
        {
            topics[id]["responses"] = ([]);
        }

        string response = sprintf("%s#%s", id, selection);
        topics[id]["responses"][response] = ([
            "selection":selection,
            "template": template
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addResponsePrerequisite(string id, string selection, mapping prerequisite)
{
    string response = sprintf("%s#%s", id, selection);
    if (member(topics, id) && member(topics[id], "responses") &&
        member(topics[id]["responses"], response))
    {
        addPrerequisite(response, prerequisite, response);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addResponseEvent(string id, string selection, string event)
{
    string response = sprintf("%s#%s", id, selection);
    if (member(topics, id) && member(topics[id], "responses") &&
        member(topics[id]["responses"], response))
    {
        topics[id]["responses"][response]["event"] = event;
    }
}

/////////////////////////////////////////////////////////////////////////////
private int isValidEffect(mapping effectMap)
{
    int ret = 0;
    string *validEffects = ({ "opinion", "attack", "move", "give" });
    string *effects = m_indices(effectMap);
    if (sizeof(effects))
    {
        ret = 1;
        foreach(string effect in effects)
        {
            ret &&= member(validEffects, effect) > -1;

            switch (effect)
            {
                case "opinion": 
                {
                    ret &&= intp(effectMap[effect]);
                    break;
                }
                case "move":
                case "give":
                {
                    ret &&= stringp(effectMap[effect]) &&
                        file_size(effectMap[effect]) &&
                        load_object(effectMap[effect]);
                    break;
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addResponseEffect(string id, string selection, mapping effect)
{
    string response = sprintf("%s#%s", id, selection);
    if (member(topics, id) && member(topics[id], "responses") &&
        member(topics[id]["responses"], response) && isValidEffect(effect))
    {
        topics[id]["responses"][response]["effect"] = effect;
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask object messageParser()
{
    return load_object("/lib/core/messageParser.c");
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isValidLiving(object livingCheck)
{
    return (livingCheck && objectp(livingCheck) &&
        (member(inherit_list(livingCheck), MaterialAttributes) > -1));
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string formatText(string text, int colorInfo, object viewer)
{
    return color(viewer->query("term"), viewer, colorInfo, format(text, 78));
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string parseTemplate(string template, string perspective,
    object initiator, object target)
{
    string message = template;
    // ##Infinitive::verb##
    // ##InitiatorName## - Initiator's name
    // ##InitiatorPossessive[::Name]## - Initiator possessive / your / Name's
    // ##InitiatorObjective## - Initiator's objective / you
    // ##InitiatorSubjective## - Initiator's subjective/pronoun / you
    // ##Target[NPOS]## - Target's (one of above 4)
    // ##HitDictionary## - random word from the hit dictionary (slash/slashes,
    //   chop/chops)
    // ##SimileDictionary## - random word from the simile dictionary

    // dictionary calls must be done first!
    int isSecondPerson = (perspective == "initiator");

    if (initiator && objectp(initiator))
    {
        message = messageParser()->parseSimileDictionary(message, initiator);
        message = messageParser()->parseVerbDictionary(message,
            "HitDictionary", initiator);

        message = messageParser()->parseVerbs(message, isSecondPerson);
    }

    if (isValidLiving(initiator))
    {
        message = messageParser()->parseTargetInfo(message, "Initiator",
            initiator, isSecondPerson);
    }

    if (isValidLiving(target))
    {
        isSecondPerson = (perspective == "target");
        message = messageParser()->parseTargetInfo(message, "Target",
            target, isSecondPerson);
    }

    message = messageParser()->capitalizeSentences(message);

    // Apply colors
    message = regreplace(message, "@S@", Speech, 1);
    message = regreplace(message, "@D@", Desc, 1);
    message = regreplace(message, "@A@((.+))@E@", Action("\\1"), 1);
    message += End;
    return message;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void displayMessage(string message, object initiator,
    object target)
{
    // This annoying loop handles the fact that everyone has different
    // setting for color.
    if (environment(initiator))
    {
        foreach(object person in all_inventory(environment(initiator)))
        {
            if (person && objectp(person))// && interactive(person))
            {
                string parsedMessage;
                int colorInfo = C_EMOTES;
                if (person == initiator)
                {
                    parsedMessage = parseTemplate(message, "initiator", initiator,
                        target);
                }
                else if (person == target)
                {
                    parsedMessage = parseTemplate(message, "target",
                        initiator, target);
                }
                else
                {
                    parsedMessage = parseTemplate(message, "other",
                        initiator, target);
                }
                tell_object(person, formatText(parsedMessage, colorInfo,
                    person));
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void displayResponse(string choice, object actor, object owner)
{
    if (member(responseKeys, choice))
    {
        string key = responseKeys[choice];
        string id = regexplode(key, "#")[0];
        displayMessage(topics[id]["responses"][key]["template"],
            actor, owner);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void displayResponses(string id, object actor, object owner)
{
    if (member(topics, id) && member(topics[id], "responses"))
    {
        responseKeys = ([]);
        string *responses = sort_array(m_indices(topics[id]["responses"]),
            (: $1 > $2 :));
        foreach(string response in responses)
        {
            if (checkPrerequisites(actor, response, owner))
            {
                string choice = to_string(sizeof(responseKeys) + 1);
                responseKeys[choice] = id + "#" + 
                    topics[id]["responses"][response]["selection"];

                tell_object(actor, format(Action(choice) + ": " +
                    Speech + responseKeys[choice] + End, 78));
            }
        }
    }
    ignoreTalk = 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int speakMessage(string key, object actor, object owner)
{
    int ret = 0;

    if (actor && mappingp(topics[key]) &&
        member(topics[key], "template") &&
        checkPrerequisites(actor, key, owner))
    {
        displayMessage(topics[key]["template"], actor, owner);

        if (member(topics[key], "responses"))
        {
            displayResponses(key, actor, owner);
            //ignoreTalk = 1;
            //call_out("displayResponses", 3, topics[key]["responses"]);
        }

        if (member(topics[key], "event"))
        {
            owner->notify(topics[key]["event"], actor);
        }
        ret = 1;
    }
    return ret;
}