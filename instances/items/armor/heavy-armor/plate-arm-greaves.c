//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
// 10/10/2017 - Valren
//    ** Created generic standard weapon
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Plate arm greaves");
        set("short", "Plate arm greaves");
        set("aliases", ({ "greaves", "arm greaves" }));
        set("blueprint", "plate arm greaves");
    }
}
