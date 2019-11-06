//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/book-vendor.c",
        "north");

    addExit("east", "/lib/tutorial/eledhel/southern-city/8x5.c");
    addExit("west", "/lib/tutorial/eledhel/southern-city/6x5.c");
}
