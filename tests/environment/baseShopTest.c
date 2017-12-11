//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Shop;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Shop = clone_object("/lib/environment/shopInventories/baseShop.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Shop);
}

/////////////////////////////////////////////////////////////////////////////
void TypeReturnsShop()
{
    ExpectEq("shop", Shop->Type());
}

/////////////////////////////////////////////////////////////////////////////
void NameSetsAndGetsName()
{
    ExpectEq("Shop", Shop->name());
    ExpectEq("Bob's Shop", Shop->name("Bob's Shop"));
    ExpectEq("Bob's Shop", Shop->name());
}

/////////////////////////////////////////////////////////////////////////////
void WelcomeMessageSetsAndGetsWelcomeMessage()
{
    ExpectEq("Welcome", Shop->welcomeMessage());
    ExpectEq("Bob's Message", Shop->welcomeMessage("Bob's Message"));
    ExpectEq("Bob's Message", Shop->welcomeMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShopTypeSetsAndGetsShopType()
{
    ExpectEq("unknown", Shop->shopType());
    ExpectEq("weapons", Shop->shopType("weapons"));
    ExpectEq("weapons", Shop->shopType());
}

/////////////////////////////////////////////////////////////////////////////
void ShopSubTypeSetsAndGetsShopSubType()
{
    ExpectEq("all", Shop->shopSubType());
    ExpectEq("swords", Shop->shopSubType("swords"));
    ExpectEq("swords", Shop->shopSubType());
}

/////////////////////////////////////////////////////////////////////////////
void Generate15RandomItemsByDefault()
{
    ExpectEq(15, Shop->randomItemsToGenerate());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetAndGetRandomItemsToGenerate()
{
    ExpectEq(15, Shop->randomItemsToGenerate());
    Shop->setRandomItemsToGenerate(9);
    ExpectEq(9, Shop->randomItemsToGenerate());
}

/////////////////////////////////////////////////////////////////////////////
void StoreItemPlacesItemInShopInventory()
{
    object sword = load_object("/lib/instances/items/weapons/swords/long-sword.c");
    sword->set("craftsmanship", 80);
    sword->set("material", "galvorn");
    sword->set("bonus attack", 5);

    ExpectEq(0, sizeof(Shop->storeInventory()));
    ExpectTrue(Shop->storeItem(sword));
    ExpectEq(1, sizeof(Shop->storeInventory()));
    destruct(sword);

    // Verify that the sword data is correct.
    sword = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    sword->set("all", Shop->storeInventory()["lib/instances/items/weapons/swords/long-sword"]["data"]);
    ExpectEq("Long sword", sword->query("name"));
    ExpectEq("galvorn", sword->query("material"));
    ExpectEq(80, sword->query("craftsmanship"));
    destruct(sword);
}

/////////////////////////////////////////////////////////////////////////////
void BuyItemRemovesItemFromInventory()
{
    object sword = load_object("/lib/instances/items/weapons/swords/long-sword.c");
    sword->set("craftsmanship", 80);
    sword->set("material", "galvorn");
    sword->set("bonus attack", 5);

    ExpectTrue(Shop->storeItem(sword));
    ExpectEq(1, sizeof(Shop->storeInventory()));
    ExpectTrue(Shop->buyItem("lib/instances/items/weapons/swords/long-sword"));
    ExpectEq(0, sizeof(Shop->storeInventory()));
    destruct(sword);
}

/////////////////////////////////////////////////////////////////////////////
void BuyItemDoesNotRemovePermanentItemsFromInventory()
{
    object sword = load_object("/lib/instances/items/weapons/swords/long-sword.c");
    sword->set("craftsmanship", 80);
    sword->set("material", "galvorn");
    sword->set("bonus attack", 5);

    ExpectTrue(Shop->storeItem(sword,1));
    ExpectEq(1, sizeof(Shop->storeInventory()));
    ExpectTrue(Shop->buyItem("lib/instances/items/weapons/swords/long-sword"));
    ExpectEq(1, sizeof(Shop->storeInventory()));
    destruct(sword);
}

/////////////////////////////////////////////////////////////////////////////
void BuyNonExistantItemReturnsFalseAndDoesNotRemoveItemsFromInventory()
{
    object sword = load_object("/lib/instances/items/weapons/swords/long-sword.c");
    sword->set("craftsmanship", 80);
    sword->set("material", "galvorn");
    sword->set("bonus attack", 5);

    ExpectTrue(Shop->storeItem(sword));
    ExpectEq(1, sizeof(Shop->storeInventory()));
    ExpectFalse(Shop->buyItem("lib/instances/items/weapons/swords/weasel"));
    ExpectEq(1, sizeof(Shop->storeInventory()));
    destruct(sword);
}

/////////////////////////////////////////////////////////////////////////////
void ResetInventoryClearsInventory()
{
    object sword = load_object("/lib/instances/items/weapons/swords/long-sword.c");
    sword->set("craftsmanship", 80);
    sword->set("material", "galvorn");
    sword->set("bonus attack", 5);

    ExpectTrue(Shop->storeItem(sword));
    ExpectEq(1, sizeof(Shop->storeInventory()));
    Shop->resetInventory();
    ExpectEq(0, sizeof(Shop->storeInventory()));
    destruct(sword);
}

/////////////////////////////////////////////////////////////////////////////
void InitiateShopInteractionShowsShopMenu()
{
    object player = clone_object("/lib/tests/support/services/mockPlayer.c");

    Shop->initiateShopInteraction(player);
    ExpectEq("[0;36mShop - [0m[0;37;1mWelcome[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mPurchase Items      [0m\n"
        "\t[[0;31;1m2[0m] - [0;32mSell Items          [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mExit Shop Menu      [0m\n"
        "[0;32;1mYou must select a number from 1 to 3.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        player->caughtMessage());
    destruct(player);
}