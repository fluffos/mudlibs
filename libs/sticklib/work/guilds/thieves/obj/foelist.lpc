// Modified:  March 18, 1998 - Kieve
//   Made it so demons could use these lists... Hey, they're
//   the bosses now.



inherit "basic/id";

#include <config.h>
#include "dirs.h"

#define SAVEFILE GDIR2 + "FOELIST"

mixed lists, writers;

void
reset(int arg)
{
    if (arg) return;

    set_name("written list");
    set_id(({ "list", "written" }));
    set_short("A written list hangs on wall");
    set_long(
      "There are two lists: black and white list. You could read them "+
      "by typing 'read black' and 'read white'.\n");

    if (!environment())
	move_object(this_object(), GDIR + "rooms/tower");

    if (!restore_object(SAVEFILE)) {
	lists = ({ ({ }), ({ }) });
	writers = ({ ({ }), ({ }) });
    }
}

int get() { return 0; }

void
init() {
    add_action("read", "read");
    add_action("write_list", "write");
    add_action("remove_from_list", "erase");
}

string *purge_list(string *l) {
    string *nl;
    int i;

    if (!l || sizeof(l) < 1) return l;

    nl = ({ });

    for (i = 0; i < sizeof(l); i++)
	if (l[i] && l[i] != "") nl += ({ l[i] });

    return nl;
}

string *query_black_list() { return lists[0]; }
string *query_white_list() { return lists[1]; }

int
read(string arg) {
    int l, i, col;
    string ln;

    if (!arg) {
	notify_fail("Read what?\n");
	return 0;
    }

    if (lower_case(arg[0..4]) == "black") l = 0;
    else if (lower_case(arg[0..4]) == "white") l = 1;
    else {
	notify_fail("What's that \"" + arg + "\"?\n");
	return 0;
    }

    if (!present("tmark", this_player())) {
	write("You can't understand anything it says.\n");
	if (this_player()->query_coder_level() > 0) {
	    write("(But as a coder, you can read even Thieve's Chant.)\n");
	} else return 1;
    }

    ln = ({ "black", "white" })[l];

    col = 0;

    write("THE " + upper_case(ln) + " LIST:\n");
    write("After each name there is (name of the thief) who wrote it.\n");
    write("Type 'write <player name> on " + ln + " list' to add a name,\n");
    write("and use 'erase <name>' to remove a name from list.\n");
    write(
      "=========================================================================\n");

    if (!lists || !lists[l] || sizeof(lists[l]) < 1) {
	write("This list is empty.\n");
	return 1;
    }

    for (i = 0; i < sizeof(lists[l]); i ++) {

	if (!stringp(lists[l][i]) || !stringp(writers[l][i])) {
	    if (!stringp(lists[l][i])) lists[l][i] = "ERROR";
	    if (!stringp(writers[l][i])) writers[l][i] = "ERROR";
	}

	write(sprintf("%-23s   ",
	    capitalize(lists[l][i]) + " (" +
	    capitalize(writers[l][i]) + ")"));
	col++;
	if (col > 2) {
	    write("\n");
	    col = 0;
	}
    }

    if (col) write("\n");

    return 1;
}

int
write_list(string arg)
{
    object tm;
    string plr, ln;
    int l;

    if (!(tm = present("tmark", this_player()))) return 0;
    /*
       if ((int)tm->query_guildmaster() >= 500)
       {
	  notify_fail("Demons may not use this board.\n");
	  return 0;
       }
    */

    if (!arg ||
      (sscanf(arg, "%s on %s list", plr, ln) != 2 &&
	sscanf(arg, "%s in %s list", plr, ln) != 2)) {
	notify_fail(
	  "Type 'write <player name> on black (or white) list' to do it.\n");
	return 0;
    }

    plr = lower_case(plr);
    ln = lower_case(ln);

    if (ln == "black") l = 0;
    else if (ln == "white") l = 1;
    else {
	notify_fail("What is that \"" + ln + "\" list then?\n");
	return 0;
    }

    if ((int)this_player()->query_level() < 10) {
	notify_fail("You have to be level 10 before you can even try.\n");
	return 0;
    }

    /* later: enforcers/gm only */
    if (tm->query_guildmaster() < 1) {
	notify_fail(
	  "Only the guild enforcers and the guildmaster can write on this list.\n");
	return 0;
    }

    if (!MASTER_OB->exists_player(plr)) {
	notify_fail(
	  "There is no player called \"" + capitalize(plr) + "\".\n");
	return 0;
    }

    if (member(lists[(l == 0 ? 1 : 0)], plr) != -1) {
	notify_fail(
	  "But " + capitalize(plr) + " is already on the other list!\n");
	return 0;
    }

    if (member(lists[l], plr) != -1) {
	notify_fail(
	  capitalize(plr) + " already is on that list.\n");
	return 0;
    }

    write("Ok. You write name of " + capitalize(plr) + " on that list.\n");
    say(this_player()->query_name() + " writes something on the list.\n");

    lists[l] += ({ plr });
    writers[l] += ({ (string)this_player()->query_real_name() });

    save_object(SAVEFILE);

    return 1;
}

int
remove_from_list(string arg)
{
    object tm;
    string plr;
    int l, ix;

    if (!(tm = present("tmark", this_player()))) return 0;
    /*
       if ((int)tm->query_guildmaster() >= 500)
       {
	  notify_fail("Demons may not use this list.\n");
	  return 0;
       }
    */

    if (!arg) {
	notify_fail("Usage: 'remove <name>'\n");
	return 0;
    }

    plr = lower_case(arg);

    if ((int)this_player()->query_level() < 10) {
	notify_fail("You have to be level 10 before you can even try.\n");
	return 0;
    }

    /* later: enforcers/gm only */
    if (tm->query_guildmaster() < 1) {
	notify_fail(
	  "Only the guild enforcers and the guildmaster can write on this list.\n");
	return 0;
    }

    if ((ix = member(lists[0], plr)) != -1) l = 0;
    else if ((ix = member(lists[1], plr)) != -1) l = 1;

    if (ix == -1 || sizeof(lists[l]) < 1) {
	notify_fail(capitalize(plr) + " is not on either list.\n");
	return 0;
    }

    if (writers[l][ix] != (string)this_player()->query_real_name() &&
      tm->query_guildmaster() < 11) {
	notify_fail("Only Guildmaster can remove names set by others.\n");
	return 0;
    }

    write("Ok. You remove name of " + capitalize(plr) + " from " +
      ({ "black", "white" })[l] + " list.\n");
    say(this_player()->query_name() + " removes something from the list.\n");

    lists[l][ix] = 0;
    writers[l][ix] = 0;

    lists[l] = purge_list(lists[l]);
    writers[l] = purge_list(writers[l]);

    save_object(SAVEFILE);

    return 1;
}
