//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
private nomask void movePlayerToStart(object player)
{
    object startingLocation = 0;
    catch (startingLocation = load_object(player->savedLocation()));

    if (startingLocation)
    {
        move_object(player, startingLocation);
    }
    else
    {
        move_object(player, "/room/city/central_park.c");
        tell_object(player, "Doh! The room you were last in during your "
            "previous session is broken.\nYou have been moved to a different "
            "location.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask object checkIfPlayerObjectExists(string name)
{
    object ret = 0;

    object *playersWithName = filter(users(), (: $1->RealName() == $2 :), name);

    if (sizeof(playersWithName))
    {
        ret = playersWithName[0];
        if (member(inherit_list(ret), "lib/realizations/player.c") < 0)
        {
            ret = 0;
        }
        if (ret)
        {
            movePlayerToStart(ret);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask object loadNewPlayerObject(string name)
{
    object ret = 0;
    object dataAccess = load_object("/lib/modules/secure/dataAccess.c");
    switch (dataAccess->playerType(name))
    {
        case "owner":
        case "god":
        case "demigod":
        case "archwizard":
        case "sage":
        case "elder":
        case "admin":
        case "senior":
        case "highwizard":
        case "creator":
        case "wizard":
        case "apprentice":
        {
            ret = clone_object("/lib/realizations/wizard.c");
            ret->restore(name);
            movePlayerToStart(ret);
            break;
        }
        default:
        {
            ret = clone_object("/lib/realizations/player.c");
            ret->registerEvent(clone_object(
                "/lib/modules/creation/initializePlayer.c"));
            ret->restore(name);
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getPlayerObject(string name)
{
    object ret = checkIfPlayerObjectExists(name);
    if (!ret)
    {
        ret = loadNewPlayerObject(name);
    }

    object channels = load_object("/lib/dictionaries/channelDictionary.c");
    if (channels)
    {
        channels->registerUser(ret);
        channels->broadcastMessage("status", sprintf("%s (%s) has joined"
            " the game.\n", capitalize(ret->RealName()),
            query_ip_number(ret) || "???"), ret);
    }
    return ret;
}
