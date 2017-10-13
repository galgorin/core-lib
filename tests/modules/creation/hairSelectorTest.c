//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

#define Block 1
#define Describe 2
#define Success 3

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/creation/hairSelector.c");
    Selector->init();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User->Name("Bob");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void InitialCreationDisplayIsCorrectForHuman()
{
    User->Race("human");
    Selector->initiateSelector(User);
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose your hair color[0m:\n"
        "\t[[0;31;1m1[0m]  - [0;32mAsh Blond           [0m"
        "\t[[0;31;1m2[0m]  - [0;32mAsh Brown           [0m\n"
        "\t[[0;31;1m3[0m]  - [0;32mAsh Gray            [0m"
        "\t[[0;31;1m4[0m]  - [0;32mAuburn              [0m\n"
        "\t[[0;31;1m5[0m]  - [0;32mBeige               [0m"
        "\t[[0;31;1m6[0m]  - [0;32mBlack               [0m\n"
        "\t[[0;31;1m7[0m]  - [0;32mBlond               [0m"
        "\t[[0;31;1m8[0m]  - [0;32mBrown               [0m\n"
        "\t[[0;31;1m9[0m]  - [0;32mBrunette            [0m"
        "\t[[0;31;1m10[0m] - [0;32mBurgundy            [0m\n"
        "\t[[0;31;1m11[0m] - [0;32mCaramel Brown       [0m"
        "\t[[0;31;1m12[0m] - [0;32mChestnut Brown      [0m\n"
        "\t[[0;31;1m13[0m] - [0;32mChocolate Brown     [0m"
        "\t[[0;31;1m14[0m] - [0;32mCopper              [0m\n"
        "\t[[0;31;1m15[0m] - [0;32mGinger              [0m"
        "\t[[0;31;1m16[0m] - [0;32mGolden              [0m\n"
        "\t[[0;31;1m17[0m] - [0;32mHoney Brown         [0m"
        "\t[[0;31;1m18[0m] - [0;32mPearl White         [0m\n"
        "\t[[0;31;1m19[0m] - [0;32mPlatinum Blond      [0m"
        "\t[[0;31;1m20[0m] - [0;32mRaven Black         [0m\n"
        "\t[[0;31;1m21[0m] - [0;32mRusset Brown        [0m"
        "\t[[0;31;1m22[0m] - [0;32mSalt and Pepper     [0m\n"
        "\t[[0;31;1m23[0m] - [0;32mSandy Brown         [0m"
        "\t[[0;31;1m24[0m] - [0;32mSilver              [0m\n"
        "\t[[0;31;1m25[0m] - [0;32mSteel Gray          [0m"
        "\t[[0;31;1m26[0m] - [0;32mStrawberry Blond    [0m\n"
        "\t[[0;31;1m27[0m] - [0;32mDo not add a hair color[0m\n"
        "[0;32;1mYou must select a number from 1 to 27.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AshBlondDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 1");
    ExpectSubStringMatch("Your hair is a moderate blond with cool hue", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AshBrownDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 2");
    ExpectSubStringMatch("Your hair is a moderate brown with cool hue", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AshGrayDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 3");
    ExpectSubStringMatch("Your hair is a moderate gray with cool hue", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AuburnDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 4");
    ExpectSubStringMatch("Your hair is a rich, deep red", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BeigeDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 5");
    ExpectSubStringMatch("Your hair is golden to light brown with a cool hue", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BlackDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 6");
    ExpectSubStringMatch("Your hair is jet black", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BlondDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 7");
    ExpectSubStringMatch("Your hair is mid-tone blond", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BrownDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 8");
    ExpectSubStringMatch("Your hair is mid-tone brown", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BrunetteDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 9");
    ExpectSubStringMatch("Your hair is a deep brown with a subtle cool hue", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BurgundyDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 10");
    ExpectSubStringMatch("Your hair is a deep, dark, very warm red-brown", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CaramelBrownDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 11");
    ExpectSubStringMatch("Your hair is warm mid-tone brown with golden hues", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChestnutBrownDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 12");
    ExpectSubStringMatch("Your hair is moderate reddish-brown", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChocolateBrownDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 13");
    ExpectSubStringMatch("Your hair is very dark brown", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CopperDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 14");
    ExpectSubStringMatch("Your hair is red-orange with very vibrant highlights", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GingerDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 15");
    ExpectSubStringMatch("Your hair is brilliant orange with deep red hues", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GoldenDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 16");
    ExpectSubStringMatch("Your hair is yellow-orange with very vibrant sheen and reddish highlights", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HoneyBrownDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 17");
    ExpectSubStringMatch("Your hair is golden to light brown with a warm hue", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PearlWhiteDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 18");
    ExpectSubStringMatch("Your hair is a lusterous white with a faint bluish sheen", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PlatinumBlondDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 19");
    ExpectSubStringMatch("Your hair is a very light, cool-hued blond", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RavenBlackDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 20");
    ExpectSubStringMatch("Your hair is glossy black with faint bluish highlights", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RussetBrownDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 21");
    ExpectSubStringMatch("Your hair is moderate to dark reddish-brown", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SaltPepperDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 22");
    ExpectSubStringMatch("Your hair is a intermingled gray and black", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SandyBrownDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 23");
    ExpectSubStringMatch("Your hair is light brown with yellowish hues", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SilverDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 24");
    ExpectSubStringMatch("Your hair is a lusterous gray with very cool, almost blue hue", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SteelGrayDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 25");
    ExpectSubStringMatch("Your hair is a shiny gray with very cool, almost blue hue", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void StrawberryBlondDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 26");
    ExpectSubStringMatch("Your hair is blond with a rich, warm red tone", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoHairColorDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 27");
    ExpectSubStringMatch("This option does not add a hair color to the player", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfAshBlondSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/ash-blond.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfAshBrownSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/ash-brown.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfAshGraySetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("3");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/ash-gray.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfAuburnSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("4");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/auburn.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfBeigeSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("5");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/beige.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfBlackSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("6");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/black.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfBlondSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("7");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/blond.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfBrownSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("8");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/brown.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfBrunetteSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("9");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/brunette.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfBurgundySetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("10");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/burgundy.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfCaramelBrownSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("11");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/caramel-brown.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfChestnutBrownSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("12");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/chestnut-brown.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfChocolateBrownSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("13");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/chocolate-brown.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfCopperSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("14");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/copper.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfGingerSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("15");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/ginger.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfGoldenSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("16");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/golden.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHoneyBrownSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("17");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/honey-brown.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfPearlWhiteSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("18");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/pearl-white.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfPlatinumBlondSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("19");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/platinum-blond.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfRavenBlackSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("20");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/raven.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfRussetBrownSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("21");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/russet-brown.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfSaltPepperSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("22");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/salt-and-pepper.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfSandyBrownSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("23");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/sandy-brown.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfSilverSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("24");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/silver.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfSteelGraySetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("25");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/steel-gray.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfStrawberryBlondSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("26");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/hair/strawberry-blond.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfNoHairColorSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("27");
    ExpectEq(sizeof(User->Traits()));
}

/////////////////////////////////////////////////////////////////////////////
void HillgarathiHighElfShowsCorrectHairList()
{
    User->Race("high elf");
    User->addTrait("/lib/modules/traits/racial/hillgarathElf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 17",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MoonHighElfShowsCorrectHairList()
{
    User->Race("high elf");
    User->addTrait("/lib/modules/traits/racial/echorluinElf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 19",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HighElfShowsCorrectHairList()
{
    User->Race("high elf");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 19",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DarkElfShowsCorrectHairList()
{
    User->Race("elf");
    User->addTrait("/lib/modules/traits/racial/darkElf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 10",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GreyElfShowsCorrectHairList()
{
    User->Race("elf");
    User->addTrait("/lib/modules/traits/racial/greyElf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 22",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SeaElfShowsCorrectHairList()
{
    User->Race("elf");
    User->addTrait("/lib/modules/traits/racial/seaElf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 13",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WoodElfShowsCorrectHairList()
{
    User->Race("elf");
    User->addTrait("/lib/modules/traits/racial/woodElf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 21",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ElfShowsCorrectHairList()
{
    User->Race("elf");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 23",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void KhazurathiDwarfShowsCorrectHairList()
{
    User->Race("dwarf");
    User->addTrait("/lib/modules/traits/racial/khazurathiDwarf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 16",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MirostiDwarfShowsCorrectHairList()
{
    User->Race("dwarf");
    User->addTrait("/lib/modules/traits/racial/mirostiDwarf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 22",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DwarfShowsCorrectHairList()
{
    User->Race("dwarf");
    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 20",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DraconidShowsCorrectHairList()
{
    User->Race("draconid");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 27",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HalfilngShowsCorrectHairList()
{
    User->Race("halfling");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 22",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GnomeShowsCorrectHairList()
{
    User->Race("gnome");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 20",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HalfElfShowsCorrectHairList()
{
    User->Race("half elf");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 27",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HalfOrcShowsCorrectHairList()
{
    User->Race("half orc");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 12",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HalfTrollShowsCorrectHairList()
{
    User->Race("half troll");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 10",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FaerieShowsCorrectHairList()
{
    User->Race("faerie");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 27",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AndurathiShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/andurathHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 19",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CelebnostiShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/celebnostHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 21",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EledheleanShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/eledhelHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 27",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EndurgishShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/endurghulHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 20",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HelcarishShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/helcarionHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 22",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HillgarathiShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/hillgarathHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 27",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void IarwatheanShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/iarwathHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 27",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LinmiriShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/linmirHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 12",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MenadrostiShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/menadrostHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 27",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TirnostiShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/tirnostHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 27",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ZhenduliShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/zhendulachHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 13",
        User->caughtMessage());
}