// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** iftp.c -- I3 file transfer utility
**
** 960205, Deathblade: created
*/

#include <mudlib.h>

inherit CMD;
inherit M_COMPLETE;
inherit M_GLOB;

private void main(string arg)
{
    string * matches;
    string mudname;
    string test;

    if ( !arg || arg == "" )
    {
        out("用法: iftp mudname\n");
        return;
    }
    matches = case_insensitive_complete(translate(arg),
                                        IMUD_D->query_up_muds());
    switch ( sizeof(matches) )
    {
    case 0:
        out("没有对应的 MUD 正在开放中。\n");
        return;

    case 1:
        mudname = matches[0];
        break;

    default:
        mudname = lower_case(mudname);
        foreach ( test in matches )
            if ( lower_case(test) == mudname )
            {
                matches = 0;
                break;
            }
        if ( !matches )
            break;
        outf("以下的 MUD 都对应了您的要求: %s\n",
               implode(matches, ", "));
        return;
    }

    new(IFTP_OB, mudname);
}
