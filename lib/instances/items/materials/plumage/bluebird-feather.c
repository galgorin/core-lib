//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Bluebird Feather");
        set("short", "Bluebird Feather");
        set("aliases", ({ "feather", "bluebird feather" }));
        set("blueprint", "bluebird feather");
    }
}
