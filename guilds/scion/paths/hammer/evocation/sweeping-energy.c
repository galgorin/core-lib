//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/guilds/scion/common/evocation/sweeping-energy.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    WeaponType = "hammer";

    addSpecification("limited by", (["equipment":({ "hammer" })]));
}
