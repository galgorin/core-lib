//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Ocarina");
        set("short", "Ocarina");
        set("aliases", ({ "ocarina", "windcap", "wind cap", "instrument" }));
        set("blueprint", "ocarina");
    }
}
