//	/bin/high_mortal/start.c
//	from the Nightmare mudlib
//	marks a new starting place for the high mortal
//	created 07 december 1992 by Descartes of Borg

#include <std.h>

inherit DAEMON;

int cmd_start(string str) {
    string a,b,tmp;

    if(!str || str != "here") {
	notify_fail("Start where?\n");
	return 0;
    }
    tmp = file_name(environment(this_player()));
    if(sscanf(tmp, "%s#%s", a, b) ==2) {
	notify_fail("You cannot start here.\n");
	return 0;
    }
    if(sscanf(tmp, "%sworkroom%s", a, b) == 2) {
	notify_fail("You cannot start here.\n");
	return 0;
    }
    if(environment(this_player())->query_property("no teleport")) {
	notify_fail("A magic force prevents you from marking this area.\n");
	return 0;
    }
    this_player()->set_primary_start(tmp);
    write("You are now set to start here.\n");
    log_file("start", this_player()->query_name()+" is set to login at "+tmp+"\n");
    return 1;
}

void help() {
    write("Syntax: <start here>\n\n"+
	"Makes your current environment (where you are now) your site\n"+
	"of login.\n");
}
