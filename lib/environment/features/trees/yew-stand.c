//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("yew stand");
    addAdjectives(({ "majestic", "towering", "tall", "massive" }));
    addTimeOfDayDescription("dawn", ({ " that the faint dawn light is just beginning to illuminate" }));
    addTimeOfDayDescription("dusk", ({ ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ " outlined in the dark", " discernable only as a darker shade of black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow",
        " layered with a dusting of snow", " encased in a film of ice" }));
    addSeasonDescription("spring", ({ " with brilliant green new growth sprouting",
        " sprouting new growth", "with tiny red flowers blossoming" }));
    addSeasonDescription("summer", ({ " with branches laden with tiny, closed cones",
        " covered with a thick blanket of needles" }));
    addSeasonDescription("autumn", ({ " with cones fallen to the ground wide open" }));

    addDescriptionTemplate("a stand of ##Adjective## yew trees");
    harvestableResource("yew", 25, "/lib/instances/items/materials/wood/yew.c",
        "a heavily-forested stand of yew trees. Several trees remain");
    harvestRequiresTool("yew", "axe");

    harvestableResource("yew cone", 25,
        "/lib/instances/items/food/plants/seeds/yew-cone.c");
    limitHarvestBySeason("yew cone", "summer");
    harvestableResource("pine nut", 25,
        "/lib/instances/items/food/plants/nuts/pine-nut.c");
    limitHarvestBySeason("pine nut", "summer");
}