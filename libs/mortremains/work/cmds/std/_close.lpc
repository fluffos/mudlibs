// _close.c
// Command to let players close doors.
// Written by Mobydick@TMI-2, 1-8-93.
// Based on an earlier version by Rusty@TMI-2.
// Closing containers is handled by an add_action in the container and not
// by this command.
// Help added by Pallando (93-02-14)
// Watcher improved the door handling a bit, 03-28-93.
// Watcher added vision checks, 04-13-93.

#include <mudlib.h>

inherit DAEMON ;

int cmd_close (string str) {

	string dir, *tmp;
	object env ;
	mapping doors ;

  if (TP->query_rest_status()) {
   write("You cannot do that while resting or sleeping.\n") ;
  return 1;
  }
        if (!str || str == "")
        {
        	notify_fail("Close what?\n");
                return 0;
        }
	if(str != "door" && sscanf(str, "%s door", dir) != 1) {
		notify_fail ("Which door do you want to close?\n") ;
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
 
	//  If the player can't see ... pick a random door. <grin>
 
	if(!this_player()->query("vision")) {
	  write("You feel around in the darkness for a door.\n");
	  dir = tmp[ random(sizeof(tmp)) ];
	}
 
	if(!dir) {
		if(sizeof(doors) > 1) {
		notify_fail ("Which door do you wish to close?\n");
		return 0; }

		dir = tmp[0];
	}
	if (!doors[dir]) {
		notify_fail ("There is no "+dir+" door.\n") ;
		return 0 ;
	}
	if (doors[dir]["status"]!="open") {
                notify_fail ("It is already closed.\n") ;
                return 0 ;
        }
	env->set_status(dir,"closed") ;
	env->update_link(dir) ;
	write ("You close the " + dir + " door.\n");
	say (this_player()->query("cap_name")+" closes the "+dir+" door.\n") ;
	return 1 ;
}

string help() {
  return @ENDHELP
Usage: close [<dir> door] [<container>]

This command allows you to attempt to close anything that might be close.
If you are trying to close a door in a room and there is more than one door,
you have to specify which door (ie - east,west,north) you want to close.

See also: open, put, get, lock, unlock
ENDHELP
  ;
}
