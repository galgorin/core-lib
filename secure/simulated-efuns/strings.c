//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
public nomask string convertDataToString(mixed data)
{
    string ret = "";

    if (objectp(data))
    {
        ret += program_name(data);
    }
    else if (pointerp(data) && sizeof(data))
    {
        ret += "({ ";
        foreach(mixed element in data)
        {
            ret += convertDataToString(element) + ", ";
        }
        ret += "})";
    }
    else if (mappingp(data))
    {
        ret += "([ ";
        mixed *indices = m_indices(data);
        foreach(mixed index in indices)
        {
            ret += convertDataToString(index) + ": " + 
                convertDataToString(data[index]) + ", ";
        }
        ret += "])";
    }
    else
    {
        ret += to_string(data);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string formatColoredString(string data, int length)
{
    string ret = "";
    string *splitString = 
        regexplode(data, "(\x1b[[0-9;]+m|\n)");

    string partialLine = "";
    int lengthOfPartialLine = 0;
    int sizeOfUnprintableCharacters = 0;

    foreach(string item in splitString)
    {
        if (item == "\n")
        {
            ret += partialLine + item;
            partialLine = "";
            lengthOfPartialLine = 0;
            sizeOfUnprintableCharacters = 0;
        }
        else if (sizeof(regexp(({ item }), "\x1b[[0-9;]+m")))
        {
            partialLine += item;
            sizeOfUnprintableCharacters += sizeof(item);
        }
        else
        {
            lengthOfPartialLine += sizeof(item);
            partialLine += item;
        }

        if (lengthOfPartialLine > length)
        {
            do
            {
                int initialIndex = length + sizeOfUnprintableCharacters - 1;
                int stringIndex;

                for (stringIndex = initialIndex;
                    ((stringIndex > 0) && (initialIndex < sizeof(partialLine)) &&
                    (partialLine[stringIndex] != ' '));
                    stringIndex--);

                if (stringIndex > 0)
                {
                    string additionalText = partialLine[0..(stringIndex - 1)];
                    string sanitizedText = regreplace(additionalText,
                        "(\x1b[[0-9;]+m)", "", 1);

                    ret += additionalText + "\n";
                    partialLine = partialLine[(stringIndex + 1)..];
                    sizeOfUnprintableCharacters -= (sizeof(additionalText) - sizeof(sanitizedText));
                    lengthOfPartialLine -= sizeof(sanitizedText);
                }
                else
                {
                    ret += partialLine;
                    partialLine = "";
                    lengthOfPartialLine = 0;
                    sizeOfUnprintableCharacters = 0;
                }
            } while ((partialLine != "") && (lengthOfPartialLine > length));
        }
    }
    return ret + partialLine;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string format(string data, int length)
{
    string ret = "";

    if (!intp(length) || length == 0)
    {
        length = 78;
    }

    if (!stringp(data))
    {
        data = to_string(data);
    }

    ret = (sizeof(regexp(({ data }), "\x1b[[0-9;]+m"))) ?
        formatColoredString(data, length) :
        (regreplace(sprintf("%=-*s", length, data), " *$", "", 1));

    if ((sizeof(ret) > 0) && ret[sizeof(ret) - 1] != '\n')
    {
        ret += "\n";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string regreplace(string inputString, string search,
    string replace, int flags)
{
    if (!stringp(inputString) || !stringp(search))
    {
        raise_error(sprintf("*Bad arg to regreplace(%O, %O, %O, %O)\n",
            inputString, search, replace, flags));
    }

    return efun::regreplace(inputString, search, replace, flags);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string lower_case(string str)
{
    return efun::lower_case(to_string(str));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string upper_case(string str)
{
    return efun::upper_case(to_string(str));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string process_string(string arg)
{
    return "Disabled\n";
}
