//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

protected string WeaponType = "ERROR";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Magical Conduit");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the magical conduit technique. This form enhances "
            "the Scion's offensive spells.");
        Setup();

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 13 ]));
        addPrerequisite(
            sprintf("guilds/scion/paths/%s/evocation/mystic-charge.c", WeaponType),
            (["type":"research"]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("affected research", (["Energy Shard":5,
            "Energy Blast": 5,
            "Energy Storm": 5,
            "Maelstrom": 5,
            "Plasma Ball": 10
        ]));
    }
}
