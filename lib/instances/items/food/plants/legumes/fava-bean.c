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
        set("name", "Fava Bean");
        set("short", "Fava Bean");
        set("aliases", ({ "bean", "fava bean" }));
        set("blueprint", "fava bean");
    }
}
