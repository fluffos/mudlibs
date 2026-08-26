 
//	File	:  /cmds/ghost/_go.c
//	Creator	:  Buddha@TMI  (09/92)
//	Updated	:  Watcher@TMI  (03/28/93) for new ghost body.
//
//	This is the ghost go command, which is similar to the standard
//	player go command, except it allows things like passing through
//	doors, etc... Typical ghost behaviour. :)

#include <mudlib.h>

inherit DAEMON ;

int cmd_go(string dir) {

	string str;
	object env;
	mapping exits, tmp;
	mapping doors ;
	string tstr ;

	env = environment(this_player());

	if (!env) { 
		write("You are in the void.  There's no way out!\n");
		return 1;
	}

	exits = env->query("exits");
	if (!mapp(exits) || member_array(dir, keys(exits)) == -1) {
		notify_fail("You can't go that way!\n");
		return 0;
	}

	// let's see if it's ok to move -- is there a pre-exit function to call?
	// if the preexit function returns 1, then the exit will be prevented!
	// otherwise the preexit function can be void or return 0, and the exit 
	// will occur after it's called.

	tmp = env->query("pre_exit_func");
	if (tmp && tmp[dir]  && call_other(env, tmp[dir])) return 1;
	
	// Now we find out if there's a special message to use when they leave.
	// if there is, we'll use it instead of the default.

	tmp = env->query("exit_msg");
 
	if (tmp && mapp(tmp) && tmp[dir]) 
	   tstr = replace_string(tmp[dir], "$N", 
			 (string)this_player()->query("cap_name") );
	else tstr = (string)this_player()->query_mout(dir);

	// Check to see if there is a closed door in the way. If so,
	// override the previous set exit message with a new one.
 
        doors = env->query("doors") ;
 
        if (doors && doors[dir]) {
	   if(member_array(doors[dir]["status"], ({"closed","locked"})) > -1) {
		tstr = "The ghost of " +
		       (string)this_player()->query("cap_name") + 
		       " passes through the " + dir + " door.";
	   write("You pass through the closed door.\n\n");
	   }
        }
 
	// Now complete the ghost's move to the new room.
 
	this_player()->move_player(exits[dir], tstr, dir);

	// We check for a post-exit function before we're done.
	// note that the player is no longer in the room, and this is also
	// our last chance to do anything before our control of the player is
	// lost.  It doesn't matter what the post-exit function returns.

	tmp = env->query("post_exit_func");
	if (tmp && mapp(tmp) && tmp[dir]) call_other(env, tmp[dir]);

	// Finally we are finished.

	return 1;
}

string help() {
	return ("Usage: go <direction>\n\n"+
"The go command will move you in the direction specified, ie \"go west\" will\n"+
"move you through the room's west exit. You can also type \"west\" and that\n"+
"will work. For the standard directions, \"w\" or other one-letter abbreviations\n"+
"will also work.\n") ;
}
 
