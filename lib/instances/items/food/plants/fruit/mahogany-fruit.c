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
        set("name", "Mahogany Fruit");
        set("short", "Mahogany Fruit");
        set("aliases", ({ "mahogany fruit", "mahogany" }));
        set("blueprint", "mahogany fruit");
    }
}
