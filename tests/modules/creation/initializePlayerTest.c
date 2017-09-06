//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Initializer;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();
    
    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->Gorthaur());

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Initializer = clone_object("/lib/modules/creation/initializePlayer.c");

    User = clone_object("/lib/realizations/player.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(Initializer);
}

/////////////////////////////////////////////////////////////////////////////
void OnRestoreSucceededCleansUpInitializer()
{
    User->registerEvent(Initializer);
    ExpectTrue(objectp(Initializer));
    User->restore("gorthaur");
    ExpectFalse(objectp(Initializer));
}

/////////////////////////////////////////////////////////////////////////////
void OnRestoreFailedInitiatesSelector()
{
    User->registerEvent(Initializer);
    ExpectTrue(objectp(Initializer));
    ExpectEq(({}), all_inventory(User));
    User->restore("newcharacter");
    ExpectTrue(objectp(Initializer));
    ExpectEq(({ "lib/modules/creation/genderSelector.c" }), 
        all_inventory(User));
}

/////////////////////////////////////////////////////////////////////////////
void OnSelectorCompletedCleansUpCurrentSelectorAndTransitionsToNextState()
{
    User->registerEvent(Initializer);
    User->restore("newcharacter");

    ExpectEq(({ "lib/modules/creation/genderSelector.c" }),
        all_inventory(User));

    object selector = first_inventory(User);
    ExpectTrue(objectp(selector));

    selector->applySelection("1");
    ExpectFalse(objectp(selector));

    ExpectEq(({ "lib/modules/creation/raceSelector.c" }),
        all_inventory(User));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerPointsSetToMaxAndPlayerMovedAndPlayerIsSavedUponCompletion()
{
    User->registerEvent(Initializer);
    User->restore("newcharacter");

    setRestoreCaller(Initializer);
    string race = User->Race("human");
    object selector = first_inventory(User);
    while (selector)
    {
        Initializer->onSelectorCompleted(selector);
        selector = first_inventory(User);
    }

    ExpectEq(User->maxHitPoints(), User->hitPoints());
    ExpectEq(User->maxSpellPoints(), User->spellPoints());
    ExpectEq(User->maxStaminaPoints(), User->staminaPoints());

    destruct(User);

    setRestoreCaller(this_object());

    User = clone_object("/lib/realizations/player.c");
    ExpectNotEq(race, User->Race());
    User->restore("newcharacter");
    ExpectEq(race, User->Race());
    ExpectEq(2, User->Str());
    ExpectEq(2, User->Int());
    ExpectEq(2, User->Dex());
    ExpectEq(2, User->Wis());
    ExpectEq(2, User->Con());
    ExpectEq(2, User->Chr());

    ExpectEq(({ }), all_inventory(User));
}