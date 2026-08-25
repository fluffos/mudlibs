//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/itemFormatters.h"

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string decorate(string text, string textClass, string type, string configuration)
{
    string ret = 0;
    int hasAnsiClass = sizeof(regexp(({ textClass }), "\x1b", 1)) > 0;

    if (configuration == "web")
    {
        // Web clients receive semantic markers instead of ANSI so the front-end
        // can theme output itself. The markers are C0-control delimited and
        // newline-free: SOH type.textClass STX ... ETX
        ret = hasAnsiClass ? text :
            sprintf("\x01%s.%s\x02%s\x03", type || "", textClass || "", text);
    }
    else
    {
        string opening = 0;
        if (hasAnsiClass)
        {
            opening = textClass;
        }
        else if (member(decorators, type) && member(decorators[type], textClass) &&
            member(decorators[type][textClass], configuration))
        {
            opening = decorators[type][textClass][configuration];
        }

        ret = opening ? (opening + text + "\x1b[0m") : text;
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string divider(string configuration, string charset)
{
    string ret = 0;

    if (configuration == "web")
    {
        ret = "\x01display.divider\x02\x03\n";
    }
    else
    {
        string opening = 0;
        if (member(decorators["dividers"], configuration))
        {
            opening = decorators["dividers"][configuration];
        }

        string lineDivider = "";
        if (charset == "screen reader")
        {
            lineDivider = sprintf("%78s\n", "");
        }
        else
        {
            lineDivider = "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n";
        }

        ret = opening ? (opening + lineDivider + "\x1b[0m") : lineDivider;
    }

    return ret;
}
