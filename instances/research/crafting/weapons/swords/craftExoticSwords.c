//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Craft Exotic Swords");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to craft katana and other 'unusual' swords out of "
            "typical bladed weapon materials such as iron, bronze, and steel.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("level", 
            (["type":"level",
              "value": 5 ]));

        addPrerequisite("lib/instances/research/crafting/weapons/swords/craftLongSwords.c", 
            (["type":"research"]));
        addPrerequisite("lib/instances/research/crafting/weapons/common/forge-welding.c",
            (["type":"research"]));
    }
}
