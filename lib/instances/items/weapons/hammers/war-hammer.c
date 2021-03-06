//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "War hammer");
        set("short", "War hammer");
        set("aliases", ({ "hammer", "warhammer", "war hammer" }));
        set("blueprint", "war hammer");
    }
}
