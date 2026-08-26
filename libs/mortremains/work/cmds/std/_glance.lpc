// _glance.c
// shortdesc, obvious exits, and inventory of room
// Shakespeare/Empacher@TMI-2

#include <commands.h>
#include <mudlib.h>
 
inherit DAEMON ;
 
string help();

int cmd_glance(string str) {
	int oldbrief;

	if (str) return write(help());

	oldbrief = this_player()->query("brief");
	this_player()->set("brief",1);
	this_player()->set_temp("force_to_look",1);
	CMD_LOOK->cmd_look();
	this_player()->delete_temp("force_to_look");
	this_player()->set("brief",oldbrief);
return 1;
}

string help() {
return(@HELP
Syntax: glance

This command gives you a breif glance at the room, providing the short
room description, obvious exits and objects within.

See also: look, brief, exits
HELP
  );
}
