/*
// Author Unknown ??
// Help added (1/28/92) by Brian
// (I am aiming for consistancy here folks...)
*/

#include <mudlib.h>

inherit DAEMON ;

int help();

int cmd_echo(string str) {
    object *admins;
    object here;

    if(!str) {
       return help();
    }
    else {
	// can't fool an admin, folks
        if (here = environment(previous_object())) {
            if (sizeof(admins = filter_array(all_inventory(here),
                                             "filter_admins", this_object())))
		message("write", sprintf(">>> %s echoes:\n",
		      capitalize(geteuid(previous_object()))),
		      admins, previous_object());
        }
	say(sprintf("%-=75s", str+"\n"));
	printf("%-=75s", "You echo: "+str+"\n");
	return 1;
    }
}

int filter_admins(object ob) {
// Beek - some admins don't care about this; it ruins the effect of social echoes
  if (ob->query("no_echo_notification")) return 0;
    return adminp(geteuid(ob)) != 0;
}

int
help() {
  write("Command: echo\nSyntax: echo <message>\n"+
        "Simply broadcasts the message passed to the room you are in.\n"+
	"Do not abuse this command, and do not use it to confuse players.\n") ;
  return 1;
}
/* EOF */
