//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/doors/baseDoor.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("portcullis");

    addDescriptionTemplate("a raised portcullis");
    useExteriorLighting();
}
