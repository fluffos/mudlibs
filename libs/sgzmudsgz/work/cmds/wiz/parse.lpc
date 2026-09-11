// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Beek - July 30, 1995
//
// Interface to the parse_sentence() debug info

#include <mudlib.h>

inherit CMD;

private void main(string str)
{
    int flag = 1;
    if (!str) {
        out("用法：Parse <sentence>\n");
        return;
    }

    if ( sizeof(str) > 3 && str[0..2] == "-v ")
    {
        flag = 2;
        str = str[3..];
    }

    out(this_body()->do_game_command(str, flag));
}
