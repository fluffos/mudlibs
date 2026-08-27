/*
 * /cmd/wiz/mage.c
 *
 * This object holds the mage wizards commands.
 * The following commands are supported:
 *
 * - snort
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
              WIZ_CMD_HELPER,
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
    return ([
	     "snort"  : "snort"
	     ]);
}

/* **************************************************************************
 * Here follows the actual functions. Please add new functions in the 
 * same order as in the function name list.
 * **************************************************************************/

/* **************************************************************************
 * snort - snort at peasants
 */
nomask int
snort(string name)
{
    object *snortees;

    CHECK_SO_MAGE;

    if (WIZ_CHECK != WIZ_MAGE)
    {
	notify_fail("No one can snort like a Mage. " +
		    "You would only look ridiculous if you tried.\n");
	return 0;
    }

    if (!stringp(name))
    {
	notify_fail("Snort at who?\n");
	return 0;
    }

    snortees = parse_this(name, "[the] %l");
    if (!sizeof(snortees))
    {
	notify_fail("Snort at who?\n");
	return 0;
    }

    if (sizeof(snortees) > 1)
    {
	notify_fail("Snorting takes a lot of concentration. You can only " +
	    "snort at one person at a time.\n");
	return 0;
    }

    if (SECURITY->query_wiz_rank(snortees[0]->query_real_name()) < WIZ_MAGE)
    {
	say(QCTNAME(this_player()) + " snorts disdainfully at " +
	    QTNAME(snortees[0]) + ".\n", ({ this_player(), snortees[0] }) );
	tell_object(snortees[0], this_player()->query_The_name(snortees[0]) +
	    " snorts disdainfully at you.\n");
	write("You snort disdainfully at " +
	    snortees[0]->query_the_name(this_player()) + ".\n");
    }
    else
    {
	write(snortees[0]->query_The_name(this_player()) +
	    " looks quite respectable and does not deserve that kind of " +
	    "treatment.\n");
    }

    return 1;
}
