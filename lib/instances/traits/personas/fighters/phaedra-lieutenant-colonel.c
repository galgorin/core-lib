//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "persona");
        addSpecification("name", "phaedra lieutenant colonel");
        addSpecification("description", "You are a lieutenant colonel in the Phaedra.");
        addSpecification("root", "fighter persona");
        "baseTrait"::reset(arg);
    }
}
