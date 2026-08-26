// open.c
// Lets players open doors.
// Written by Mobydick@TMI-2, 1-8-93.
// Based on an earlier version by Rusty@TMI-2.
// Opening containers is handled by an add_action in the container, not by
// this command.
// Updated by Watcher@TMI-2 (03/28/93) to handle "open door".
// Watcher@TMI added vision checks (04/13/93).

#include <mudlib.h>

inherit DAEMON ;

int cmd_open (string str) {

	string dir, *tmp;
	object env ;
	mapping doors ;

	if(!str || (sscanf(str,"%s door", dir) != 1 && str != "door")) {
		notify_fail("What did you want to open?\n");
		return 0 ;
	}
	env = environment(this_player()) ;
	if (!env) {
		notify_fail ("The void has no doors.\n") ;
		return 0 ;
	}
	doors = env->query("doors") ;
 
	if (!doors) {
		notify_fail ("There are no doors here.\n") ;
		return 0 ;
	}
 
	tmp = keys( doors );
 
	if(str == "door") {
		if(sizeof(doors) > 1) {
		notify_fail("Which door did you wish to open?\n");
		return 0; }

		dir = tmp[0];
	}
 
	//  If the user can't see ... then pick a random door. <grin>
 
	if(!this_player()->query("vision"))  {
	  write("You feel around in the darkness for a door.\n");
	  dir = tmp[ random(sizeof(tmp)) ];
	}
 
	if (!doors[dir]) {
		notify_fail ("There is no "+dir+" door.\n") ;
		return 0 ;
	}
	if (doors[dir]["status"]=="open") {
		notify_fail ("It is already open.\n") ;
		return 0 ;
	}
	if (doors[dir]["status"]=="locked") {
		notify_fail ("That door is locked.\n");
		return 0 ;
	}
	env->set_status(dir, "open") ;
	env->update_link(dir) ;
	write ("You open the " + dir + " door.\n");
	say (this_player()->query("cap_name")+" opens the "+dir+" door.\n") ;
	return 1 ;
}

string help() {
	return ("Syntax: open <dir> door  -or-  open <container>\n\n"+
"The open command lets you open a door or container if it is not already\n"+
"open and is is not locked.\n\n"+
"See also: get, put, close, lock, unlock\n"
	) ;
}
