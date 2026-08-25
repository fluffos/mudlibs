/*
 * /cmd/wiz/keeper.c
 *
 * This object holds the commands reserved for administrators.
 */

#pragma save_binary

inherit "/cmd/std/command_driver";

#include <files.h>
#include <language.h>
#include <macros.h>
#include <std.h>
#include <stdproperties.h>

#define CHECK_SO_KEEPER	if (WIZ_CHECK < WIZ_KEEPER) return 0; \
			if (this_interactive() != this_player()) return 0

/* **************************************************************************
 * Return a list of which souls are to be loaded.
 * The souls are listed in order of command search.
 */
get_soul_list()
{
    return ({ WIZ_CMD_KEEPER,
              WIZ_CMD_ARCH,
              WIZ_CMD_LORD,
	      WIZ_CMD_NORMAL,
	      WIZ_CMD_HELPER,
	      WIZ_CMD_PILGRIM,
	      WIZ_CMD_APPRENTICE,
	      MBS_SOUL });
}

/* **************************************************************************
 * Return a proper name of the soul in order to get a nice printout.
 */
get_soul_id()
{
    return WIZNAME_KEEPER;
}

/* **************************************************************************
 * The list of verbs and functions. Please add new in alfabetical order.
 */
mapping
query_cmdlist()
{
    return ([
	     "keeper":"keeper"
	     ]);
}
    
/* **************************************************************************
 * Here follows the actual functions. Please add new functions in the 
 * same order as in the function name list.
 * **************************************************************************/

/* **************************************************************************
 * keeper - make an archwizard into keeper or vice versa.
 */
int
keeper(string str)
{
    string *parts;

    CHECK_SO_KEEPER;

    if (!strlen(str))
    {
	notify_fail("Syntax: keeper <name> [arch/keeper]\n");
	return 0;
    }

    if (sizeof(parts = explode(lower_case(str), " ")) != 2)
    {
	notify_fail("Syntax: keeper <name> [arch/keeper]\n");
	return 0;
    }

    switch(parts[1])
    {
    case "arch":
	if (SECURITY->query_wiz_rank(parts[0]) != WIZ_KEEPER)
	{
	    write("Only a keeper can be made into an arch this way!\n");
	    return 1;
	}

	if (SECURITY->set_keeper(parts[0], 0))
	{
	    write("Made keeper " + capitalize(parts[0]) + " an arch.\n");
	    return 1;
	}

	notify_fail("Failed to make " + capitalize(parts[0]) + " an arch.\n");
	return 0;

    case "keeper":
	if (SECURITY->query_wiz_rank(parts[0]) != WIZ_ARCH)
	{
	    write("Only an arch can be made into a keeper this way!\n");
	    return 1;
	}

	if (SECURITY->set_keeper(parts[0], 1))
	{
	    write("Made archwizard " + capitalize(parts[0]) + " a keeper.\n");
	    return 1;
	}

	notify_fail("Failed to make " + capitalize(parts[0]) + " a keeper.\n");
	return 0;

    default:
	notify_fail("Syntax: keeper <name> [arch/keeper]?\n");
	return 0;
    }

    write("Fatal end in switch() in 'keeper'!\n");
    return 1;
}
