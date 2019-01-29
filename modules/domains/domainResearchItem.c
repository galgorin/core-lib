//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/researchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask int addSpecification(string type, mixed value)
{
    int ret = 0;

    switch(type)
    {
        case "power":
        {
            if(intp(value) && (value > 0))
            {
                researchData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - domainResearchItem: the '%s'"
                    " specification must be an integer greater than 0.\n",
                    type));
            }
            break;           
        }      
        case "affected buildings":
        {
            object domains = getDictionary("domain");

            if (pointerp(value) && sizeof(value) && domains &&
                domains->validBuildings(value))
            {
                researchData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - domainResearchItem: the '%s'"
                    " specification must be a set of valid buildings.\n",
                    type));
            }
            break;
        }   
        case "building effects":
        {
            object domains = getDictionary("domain");

            if (mappingp(value) && sizeof(value) && domains &&
                domains->validBuildingEffects(value))
            {
                researchData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - domainResearchItem: the '%s'"
                    " specification must be a valid building effects mapping.\n",
                    type));
            }
            break;
        }   
        case "troop effects":
        {
            object domains = getDictionary("domain");

            if (mappingp(value) && sizeof(value) && domains &&
                domains->validTroopEffects(value))
            {
                researchData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - domainResearchItem: the '%s'"
                    " specification must be a valid troop effects mapping.\n",
                    type));
            }
            break;
        }   
        default:
        {
            ret = "researchItem"::addSpecification(type, value);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "domain");
        addSpecification("scope", "domain");
        addSpecification("effect", "strategic");
    }
}