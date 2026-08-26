// File: /cmds/std/_go.c
// Code to move a player from one room to another.
// This code used to be in the player object, which was wasteful because
// it meant the code was duplicated in each player. By adding the "go" verb
// to the movement command, it is possible to stick the code into a normal
// command, saving mucho RAM. It is wise to alias "n" to "go north", etc,
// for compatibility with people's expectations, and in fact this is done
// in the standard distribution.
// Written by Buddha in October 1992, probably. The lame-o didn't put a
// header on. This header was added by Mobydick on 11-11-92.

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

int cmd_go(string dir) {
	mapping exits, tmp, doors;     
	object env, ob, *obs;
	int i, sz, flag;
	string tstr;

	ob = this_player();
	if(!ob) ob = previous_object();
	env = environment(ob);
	if(!env) { 
		write("You are in the void.  There's no way out!\n");
		return 1;
	}
	exits = env->query("exits");
	if(!mapp(exits) || member_array(dir, keys(exits)) == -1) {
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
//	tmp = env->query("pre_exit_func");
//	if(tmp && tmp[dir] && call_other(env, tmp[dir])) return 1;
	tmp = env->query("pre_exit_func/"+dir);
	if (tmp && call_other(env, tmp)) return 1;
// Now we find out if there's a special message to use when they leave.
// if there is, we'll use it instead of the default.
//	tmp = env->query("exit_msg");
//	if(tmp && mapp(tmp) && tmp[dir]) {
	tmp = env->query("exit_msg/"+dir);
	if (tmp) {
		tstr = replace_string(tmp, "$N", (string)ob->query("cap_name"));
//		ob->move_player(exits[dir], tstr);
	} else {
		tstr = ob->query_mout(dir);
//		ob->move_player(exits[dir], tstr);
	}
	ob->move_player(env->query("exits/"+dir), tstr);
// We check for a post-exit function. Note that the player is no longer
// in the room, and this is also our last chance to do anything before
// our control of the player is lost. It doesn't matter what the
// post-exit function returns.
//	tmp = env->query("post_exit_func");
//	if(tmp && mapp(tmp) && tmp[dir]) call_other(env, tmp[dir]);
	tmp = env->query("post_exit_func/"+dir);
	if (tmp) call_other(env, tmp);
// Now we check for party members and move them. The call_out will give
// the effect of party members following their leader.
	if((string)ob->query("leader") &&
	((string)ob->query("leader")) == ((string)ob->query("name"))) {
		obs = PARTY_D->query_members(ob);
		sz = sizeof(obs);
		tmp = env->query("exits/"+dir);
		for(i = 0; i < sz; i++) {
			if(!obs[i]) continue;
			if(environment(obs[i]) != env) {
				tell_object(obs[i], "Your party moved without you.\n");
				continue;
			}
			tstr = obs[i]->query_mout(dir);
//			obs[i]->move_player(exits[dir], tstr);
			obs[i]->move_player(tmp, tstr);
			flag = 1;
		}
		if(flag) write("Your party follows you.\n");
	}
// Finally we are finished.
	return 1;
}

string help() {
	return(@HELP
Syntax: go <direction>

The go command will move you in the direction
specified, ie: "go west" will move you through
the room's west exit. You can also type "west"
and that will work. For the standard directions,
"w" or other one-letter abbreviations will also
work.

See also: exits, glance
HELP
  );
}

