//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Thwart Smite");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a master smite - the thwart smite. This is a high "
            "horizontal smite with the backhand edge from the right and then the "
            "main edge from the left. This breaks the from-the-roof guard.");

        addSpecification("limited by", (["equipment":({ "staff" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 17 ]));

        addPrerequisite("lib/guilds/scion/paths/staff/forms/over-smite.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus staff", 1);
        addSpecification("bonus attack", 2);
    }
}