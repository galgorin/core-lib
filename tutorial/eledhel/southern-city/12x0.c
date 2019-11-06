//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/military/gate-house.c", 
        "north", "/lib/tutorial/eledhel/southern-city/12x1.c");
    addBuilding("/lib/environment/buildings/military/tall-wall-tower.c", 
        "west");
    addBuilding("/lib/environment/buildings/military/tall-wall-tower.c", 
        "east");

    addExit("south", "/lib/tutorial/eledhel/southern-rural/3x9.c");
}
