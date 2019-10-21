//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("south", "/lib/tutorial/eledhel/southwest-rural-one/21x0.c");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addExit("east", "/lib/tutorial/eledhel/southwest-rural-one/22x1.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
}
