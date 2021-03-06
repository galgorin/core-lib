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
        set("name", "Basmati Rice");
        set("short", "Basmati Rice");
        set("aliases", ({ "basmati rice", "rice" }));
        set("blueprint", "basmati rice");
    }
}
