/*
 * Copyright (c) 1991 Chalmers Computer Society
 *
 * This code may not be copied or used without the written permission
 * from Chalmers Computer Society.
 */
/*
   The standard command driver of Genesis
*/
inherit "/cmd/std/command_driver";

#include <macros.h>
#include <std.h>
#include <stdproperties.h>
#include "/d/Standard/sys/useful.h"

create()
{
    seteuid(getuid(this_object())); 
}

/*
 * What souls to use as misc souls
 */
string *
replace_soul()
{
    return
	({
	    MASTER, 
	    "/cmd/live/things", 
	    "/cmd/live/social",
	    "/cmd/live/state", 
	    "/cmd/live/info"
	 });
}

/* **************************************************************************
 * Return a proper name of the soul in order to get a nice printout.
 */
string
get_soul_id()
{
    string *st;

    st = explode(file_name(this_object()),"/");
    return st[sizeof(st) - 1];
}

/* **************************************************************************
 * This is a command soul.
 */
int
query_cmd_soul()
{
    return 1;
}

/* **************************************************************************
 * The list of verbs and functions. Please add new in alfabetical order.
 */
mapping
query_cmdlist()
{
    return ([
	     "help":"genesis_help",
	     "pomoc":"genesis_help",
	     "pomocy":"genesis_help",
	     ]);
}

/* **************************************************************************
 * Here follows the actual functions. Please add new functions in the 
 * same order as in the function name list.
 * **************************************************************************/


/*
 * help - This is specific Genesis help information.
 *
 * This is called before the standard help, so as to be able to override
 * standard help on a given subject.
 *
 * No notify_fail is used as the standard help will fix proper fail msgs.
 */
public int
genesis_help(string what)
{
    int wl;
    string nam;

    if (!strlen(what))
	return 0; /* Let the standard help handle it */

    if (TI && (nam = TI->query_real_name()) == geteuid(TI))
	wl = SECURITY->query_wiz_level(nam);
    else
	wl = 0;

    if (wl && file_size("/d/Standard/doc/help/wizard/" + what) > 0)
    {
	TI->more("/d/Standard/doc/help/wizard/" + what, 1,
		 TP->query_prop(PLAYER_I_MORE_LEN));
	return 1;
    }
    
    if (file_size("/d/Standard/doc/help/mortal/" + what) > 0)
    {
	TI->more("/d/Standard/doc/help/mortal/" + what, 1,
		 TP->query_prop(PLAYER_I_MORE_LEN));
	return 1;
    }
    
    if (file_size("/d/Standard/doc/help/mortal/help") > 0)
    {
	TI->more("/d/Standard/doc/help/general/help", 1,
		 TP->query_prop(PLAYER_I_MORE_LEN));
	return 1;
    }
    return 0;
}
