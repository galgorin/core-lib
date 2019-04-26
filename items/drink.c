//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    switch(element)
    {
        case "type":
        {
            ret = "drink";
            break;
        }
        case "blueprint":
        {
            ret = member(itemData, "blueprint") ? itemData["blueprint"] :
                "item"::query("drink type");
            break;
        }
        case "drink type":
        {
            ret = member(itemData, "drink type") ? itemData["drink type"] :
                materialsObject()->getBlueprintDetails(this_object(), "skill to use");
            break;
        }
        case "low light description":
        {
            ret = "The silhouette of a small, roughly cylindrical shape";
            break;
        }
        case "dim light description":
        {
            ret = "Something that appears to be a beverage";
            break;
        }
        case "crafting guilds":
        {
            object guilds = load_object("/lib/dictionaries/guildsDictionary.c");
            if (guilds)
            {
                ret = guilds->guildsInClass("brewing");
            }
            break;
        }
        default:
        {
            ret = "item"::query(element);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkBlueprint(string data)
{
    int ret = 0;
    if (data && stringp(data))
    {
        ret = materialsObject()->isValidDrinkBlueprint(data);
    }

    if (ret)
    {
        itemData["blueprint"] = data;
    }
    else
    {
        raise_error(sprintf("Drink: The 'blueprint' element must be"
            " a string as defined in the keys of the drinks"
            " mapping in %s.\n",
            MaterialsBlueprint));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int set(string element, mixed data)
{
    int ret = 0;

    if (element && stringp(element))
    {
        switch (element)
        {
            case "blueprint":
            {
                ret = checkBlueprint(data);
                break;
            }
            default:
            {
                ret = "item"::set(element, data);
            }
        }
    }
    return ret;
}
