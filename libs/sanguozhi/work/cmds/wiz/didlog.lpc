// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** didlog.c -- print out a portion of the DID_D log
**
** 950821, Deathblade: created
*/

#include <mudlib.h>
#include <daemons.h>

inherit CMD;

private void main(string str) {
    int ndays;
    string header;
    string pattern;

    if ( !str )
        ndays = 1;
    else if ( !(ndays = to_int(str)) ) {
        if (sscanf(str, "%s %d", pattern, ndays) != 2) {
            pattern = str;
            ndays = 1;
        }
    }

    if ( ndays == 1 )
        header = "DID_D 对昨天进行汇报";
    else
        header = sprintf("DID_D 对过去的 %d 天进行汇报", ndays);

    out(DID_D->get_did_info(time() - ndays * 24 * 60 * 60,
        ({ header,
          repeat_string("-", sizeof(header)),
          "" }),
        pattern));
}

