//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/jeweler.c",
        "east", "/lib/tutorial/eledhel/southern-city/13x6.c");

    addExit("north", "/lib/tutorial/eledhel/southern-city/12x7.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/12x5.c");
}
