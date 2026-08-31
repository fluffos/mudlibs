//      /bin/user/_wimpy.c
//      from the Nightmare mudlib
//      for wimping out, easy to change to set specific percents
//      but I do not believe in that, so this just toggles on or off
//      created by Descartes of Borg 10 may 1993
//      rewritten by wiz of primal darkness 26 feb 2002

#include <std.h>

inherit DAEMON;

int cmd_wimpy(string arg) {
    int p;

    if (!arg) {
        if (this_player()->query_wimpy() == 0)
            write("You do not have wimpy turned on.");
        else
            write("Your wimpy is set at: "+this_player()->query_wimpy()+"%");
        return 1;
    }
    if (arg == "off") {
	write("brave mode!");
	this_player()->set_wimpy(0);
        return 1;
    }
    if (sscanf(arg, "on %d", p) != 1)
        return notify_fail("Syntax: wimpy <off|on> [percentage]\n");

    if (p < 1 || p > 60)
        return notify_fail("percentage must be between 1 and 60!\n");

    this_player()->set_wimpy(p);
    write("wimpy mode set at "+p+"%");
    return 1;
}

void help() {
    write("Syntax: wimpy <off|on> [percentage]\n\n"
        "When on, it will have you automatically flee from combat when your hit "
        "points are reduced below the given percentage of your total.\n\n"
        "%^BOLD%^%^RED%^NOTE%^RESET%^: Wimpy will only work once every 12 seconds. "
        "It is NOT a guarantee against dying!\n\n"
        "See also: wimpydir, kill"
    );
}
