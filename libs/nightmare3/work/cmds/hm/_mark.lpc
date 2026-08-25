//	/bin/high_mortal/_mark.c
//	from the Nightmare mudlib
//	Command for marking teleport sites
//	created by Descartes of Borg 09 december 1992

#include <std.h>

inherit DAEMON;

int cmd_mark(string str) {
    object here;
    string a, b;

    if(!str) return 0;
    if(str != "here") return 0;
    here = environment(this_player());
    if(here->query_property("no teleport")) {
	notify_fail("A magic force prevents you from marking this site.\n");
	return 0;
    }
    if(sscanf(file_name(here), "%s#%s", a, b) == 2) {
	notify_fail("You fail to mark this site.\n");
	return 0;
    }
    if(sscanf(file_name(here), "%sworkroo%s", a, b) == 2) {
	notify_fail("You fail to mark this site.\n");
	return 0;
    }
    if((int)this_player()->query_mp() < 10) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    this_player()->add_mp(-10);
    this_player()->setenv("marked", file_name(here));
    write("You mark "+lower_case((string)here->query_short())+"\n");
    return 1;
}

void help() {
    write("Syntax: <mark here>\n\n"+
	"Marks your current location for future teleportation.\n");
}
