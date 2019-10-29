//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/military/tall-stone-wall.c",
        "west");

    addDecorator("inner north-south wall");

    addExit("north", "/lib/tutorial/eledhel/southern-city/1x3.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/2x2.c");
}
