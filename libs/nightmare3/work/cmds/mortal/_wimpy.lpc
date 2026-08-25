//      /bin/user/_wimpy.c
//      from the Nightmare mudlib
//      for wimping out, easy to change to set specific percents
//      but I do not believe in that, so this just toggles on or off
//      created by Descartes of Borg 10 may 1993

#include <std.h>

inherit DAEMON;

int cmd_wimpy(string arg) {
    if(arg != "on" && arg != "off") {
        notify_fail("Syntax: <wimpy [on|off]>\n");
        return 0;
    }
    if(arg == "off") {
	write("Brave mode.\n");
	this_player()->set_wimpy(0);
    }
    else {
        this_player()->set_wimpy(23);
        write("Wimpy mode.\n");
    }
    return 1;
}

void help() {
    write("Syntax: <wimpy [on|off]>\n\n"
        "When on, it will have you automatically flee from combat\n"
        "when your hit points are reduced below 23% of your total.\n"
        "Of course, some combat circumstances make it possible to lose\n"
        "more than 23% in one shot, so this is not fail safe.\n"
        "See also: wimpydir, kill\n"
    );
}
