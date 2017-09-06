//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/creation/skillSelectorSubmenu.c";

/////////////////////////////////////////////////////////////////////////////
protected mapping skillMenuSetup()
{
    return SkillDictionary ? 
        SkillDictionary->creationListForSkillType("language") : ([]);
}