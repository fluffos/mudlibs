/*
 * This is a temporary room object where the player is moved when he
 * melts to earth. This room is to be _cloned_, so it should be impossible
 * for other players to come here. 
 */

#include "priest_room.h"
#include <living_defs.h>

#define FP_COST 5

object prev_room, pl;
object earth_ob;
int order, pk_time;

void create_room()
{
    set_light_level(LT_DIM);
    set_short("Melted to the earth");
    set_long("You can see nothing but dirt. Use 'out' to return back on \
the ground.");
    set(SKIP_EXITS);
    set(PREVENT_TELEPORT);
}

void init_room() {
    if(this_player() != pl) {
	this_player()->tell_me("How on earth did you get here??? \
Teleporting to church...");
	this_player()->move_player("X", "/room/church");
	return;
    }
    add_action("filter_commands", "", 1);
    add_action("out_cmd", "out");
}

void set_previous_room(object room, object who, object ob) {
    pl = who;
    prev_room = room;
    order = who->query_guild_object()->query_order();
    pk_time = who->query(LIV_OK_TO_PK);
    earth_ob = ob;
    set_heart_beat(1);
}

void self_destruct() {
    object ob, *inv;
    int i;

    inv = all_inventory(this_object());
    i = sizeof(inv);
    while(--i>=0) {
	ob = inv[i];
	if(ob && query_once_interactive(ob))
	    ob->move_player("X", "/room/church");
    }
    destruct(earth_ob);
    destruct(this_object());
}

status filter_commands(string args) {
    string cmd;

    cmd = query_verb();
    switch(cmd) {
    case "score": case "session":
    case "help" : case "advice":
    case "cash": case "sc": case "spells": case "potions":
    case "look": case "who": case "pskills": case "askills":
    case "comm":
	return 0;

    case "quit":
	self_destruct();
	return 0;

	// followers of caine can't rest
    case "rest": case "sit":
	if(order!=-1) return 0;

    }
    pl->tell_me("You can't do that while being melted to the ground.");
    return 1;
}


status out_cmd(string str) {
    set_heart_beat(0);
    remove_call_out("out_cmd");
    if(!prev_room) {
	pl->tell_me("There's something wrong with that room where you were \
before melting to the earth. Teleporting you to church.");
	pl->move_player("X", "/room/church");
    } else {
	pl->tell_me("You regain your original form stand up.");
	move_object(pl, prev_room);
	prev_room->tell_here(":%<me.capname>% raises from the earth!",
	  0,0,pl,pl,0,0);
    }
    if(pk_time)
	pl->set(LIV_OK_TO_PK, pk_time);
    self_destruct();
    return 1;
}


heart_beat() {
    if(pl->query_fp()<FP_COST) {
	out_cmd();
	return;
    }
    pl->add_fp(-FP_COST);
}


