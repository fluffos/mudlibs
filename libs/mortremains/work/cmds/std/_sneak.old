// _sneak.c
// Code to move a player from one room to another.
// If the sneak succeeds then no messages are printed.
// Written by Mobydick@TMI-2, 12-22-92. Copied and only slightly modified
// from _go.c, written by Buddha or someone earlier.
// Fixed type checking for all_inventory (around line 60 and 80)
// Leto 941111

#include <mudlib.h>

inherit DAEMON ;

int cmd_sneak(string dir) {

	string str;
	int livflag, skill, sneakprob, i ;
	object env, frog;
	mapping exits, tmp, next, doors;
	string tstr ;
     object *invent;

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

// Check to see if there is a door in that exit, and if so, is it closed
// or locked. If it is, don't permit the move.
        doors = env->query("doors");
        if(doors && doors[dir]) {
                if(doors[dir]["status"] == "closed" ||
                doors[dir]["status"] == "locked") {
                        notify_fail("The door is closed.\n");
                        return 0;
                }
        }

	// let's see if it's ok to move -- is there a pre-exit function to call?
	// if the preexit function returns 1, then the exit will be prevented!
	// otherwise the preexit function can be void or return 0, and the exit 
	// will occur after it's called.

	tmp = env->query("pre_exit_func");
	if (tmp && tmp[dir]  && call_other(env, tmp[dir])) return 1;
	
	// Now we see if the sneak is successful. If so, we leave without
	// printing any messages. If not, off we go, messages and all.

	skill = this_player()->query_skill("Stealth") ;
	sneakprob = 20+skill*2 ;
// If there is a living object in the next room, give skill points.
	livflag = 0 ;
	frog = find_object_or_load(exits[dir]) ;
	invent = all_inventory(frog) ;
	for (i=0;i<sizeof(invent);i++) {
		if (living(invent[i])) {
			livflag = 1 ;
			continue ;
		}
	}
	if (livflag) {
		this_player()->improve_skill("Stealth", 5) ;
	}
	if (random(100)<sneakprob) {
		this_player()->move_player(exits[dir],"SNEAK") ;
	} else {
		tmp = env->query("exit_msg");
		if (tmp && mapp(tmp) && tmp[dir]) {
			tstr = replace_string (tmp[dir],"$N",(string)this_player()->query("cap_name") );
			this_player()->move_player(exits[dir],tstr) ;
		} else {
			tstr = this_player()->query_mout(dir) ;
			this_player()->move_player(exits[dir],tstr) ;
		}
	}
// If there is a living object in the old room, give skill points.
	livflag = 0 ;
	invent = all_inventory(env) ;
	for (i=0;i<sizeof(invent);i++) {
		if (living(invent[i])) {
			livflag = 1 ;
			continue ;
		}
	}
	if (livflag) {
		this_player()->improve_skill("Stealth", 5) ;
	}

	// We check for a post-exit function before we're done.
	// note that the player is no longer in the room, and this is also
	// our last chance to do anything before our control of the player is
	// lost.  It doesn't matter what the post-exit function returns.

	tmp = env->query("post_exit_func");
	if (tmp && mapp(tmp) && tmp[dir]) call_other(env, tmp[dir]);

	// Finally we are finished.

	return 1;
}

int help() {
	write ("Usage: sneak <direction>\n\n"+
"The sneak command will let you try to move in the direction specified,\n"+
"moving silently (ie, no message will be printed). You may fail to sneak\n"+
"and you will not be told whether you succeeded or failed.\n") ;
	return 1 ;
}

