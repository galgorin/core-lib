//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Buckeye Globose");
        set("short", "Buckeye Globose");
        set("aliases", ({ "buckeye globose", "globose" }));
        set("blueprint", "buckeye globose");
    }
}
