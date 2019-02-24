//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Social";
        addCommandTemplate("party [.*]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object party = initiator->getParty();
        if (party)
        {
            string message = 0;
            if (sizeof(regexp(({ command }), "^party (.+)")))
            {
                ret = 1;
                message = regreplace(command, "^party (.+)", "\\1");

                object channels = load_object("/lib/dictionaries/channelDictionary.c");
                if (channels && sizeof(message))
                {
                    channels->broadcastMessage(party->partyName(), message, initiator);
                }
            }
            else
            {
                notify_fail("What do you want to say on the party line?\n");
            }
        }
        else
        {
            notify_fail("In order to use the party command, you need to be in a party.\n");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string wildcardMeaning(string colorConfiguration)
{
    return "\x1b[0;31;1m<Message to speak>\x1b[0m";
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Send a message to every member of your party";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Party allows a player to display a message to all players "
        "in their party who are currently logged on.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: tell, whisper, reply, say, guild, faction, race, "
        "and shout";
}
