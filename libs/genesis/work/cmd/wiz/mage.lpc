/*
 * /cmd/wiz/mage.c
 *
 * This object holds the mage wizards commands.
 * The following commands are supported:
 *
 */

#pragma no_clone
#pragma no_inherit
#pragma save_binary
#pragma strict_types

inherit "/cmd/std/command_driver";

#include <macros.h>
#include <std.h>

#define CHECK_SO_MAGE 	if (WIZ_CHECK < WIZ_MAGE) return 0; \
			if (this_interactive() != this_player()) return 0

/* **************************************************************************
 * Return a list of which souls are to be loaded.
 * The souls are listed in order of command search.
 */
nomask string *
get_soul_list()
{
    return ({ WIZ_CMD_MAGE,
	      WIZ_CMD_NORMAL,
	      WIZ_CMD_APPRENTICE,
	      MBS_SOUL });
}

/* **************************************************************************
 * Return a proper name of the soul in order to get a nice printout.
 */
nomask string
get_soul_id()
{
    return WIZNAME_MAGE;
}

/* **************************************************************************
 * The list of verbs and functions. Please add new in alfabetical order.
 */
nomask mapping
query_cmdlist()
{
    return ([ ]);
}

/* **************************************************************************
 * Here follows the actual functions. Please add new functions in the 
 * same order as in the function name list.
 * **************************************************************************/

