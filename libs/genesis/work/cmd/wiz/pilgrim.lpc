/*
 * /cmd/wiz/pilgrim.c
 *
 * This object holds the pilgrim wizards commands.
 */

#pragma no_clone
#pragma no_inherit
#pragma strict_types
#pragma save_binary

inherit "/cmd/std/command_driver";

#include <std.h>

#define CHECK_SO_WIZ 	if (WIZ_CHECK < WIZ_PILGRIM) return 0; \
			if (this_interactive() != this_player()) return 0

/* **************************************************************************
 * Return a list of which souls are to be loaded.
 * The souls are listed in order of command search.
 */
nomask string *
get_soul_list()
{
    return ({ WIZ_CMD_PILGRIM, 
	      WIZ_CMD_APPRENTICE,
	      MBS_SOUL });
}

/* **************************************************************************
 * Return a proper name of the soul in order to get a nice printout.
 */
nomask string
get_soul_id()
{
    return WIZNAME_PILGRIM;
}

/* **************************************************************************
 * The list of verbs and functions. Please add new in alfabetical order.
 */
nomask mapping
query_cmdlist()
{
    return ([
	     "pingmud":"pingmud",
	 ]);
}


/* **************************************************************************
 * Here follows the actual functions. Please add new functions in the 
 * same order as in the function name list.
 * **************************************************************************/

/* **************************************************************************
 * pingmud - send a udp ping to another mud
 *
 * NOTE: This code is doubled in WIZ_CMD_ARCH.
 *
 * When I know how to limit pilgrim to ping only their own mud, I'll add that
 * code here.
 */
nomask int
pingmud(string arg)
{
#ifdef UDP_MANAGER    
    string a, b, *ix;
    int port;
    mapping p;
    int il;

    CHECK_SO_WIZ;

    ix = UDP_MANAGER->query_known_muds();

    if (member_array(arg, ix) >= 0)
    {
	p = UDP_MANAGER->query_mud_info(arg);
	UDP_MANAGER->send_ping_q(p["HOSTADDRESS"], p["PORT"]);
    }
    else if (stringp(arg) && sscanf(arg,"%s %s", a, b) == 2)
    {
	UDP_MANAGER->send_ping_q(a, b);
    }
    else
    {
	notify_fail("SYNTAX: pingmud host port / mudname\n");
	return 0;
    }
    write("Ok.\n");
    return 1;
#endif
    return 0;
}
