/*
 * MOONWELL
 *
 * Well, this isn't actually a well, but I got the idea from Ramlin,
 * and I couldn't deny that it wouldn't be a good idea to have a place
 * where priests can empty their staffs before they leave, so that precious
 * spell points wouldn't be wasted. Venom had a similar idea (Ramlin
 * had told it to him?), but he called it "manapool", so I made
 * a cross: "moonpool".
 * 
 * -- Chopin
 */

#include "../gardens.h"
#include <conditions.h>
#include <virtual_room.h>
#include <macros.h>

#define SAVE_FILE PRIEST_SAVE_DIR "moonwell"

#define DECR_DELAY 300 // 1 sp / 5 mins
#define MAX_SPS_IN_POOL 10000

#define DAY_LONG "You are standing inside a circle of stones. The ground \
is hard and paths lead to several diractions, probably this have once \
been a sacred place where priests have come to meditate. The forest \
has taken this place to it's possession long time ago, almost hiding \
the huge stones. Where once must have been some kind of an altar, is now \
standing a maple, but at the exact center of the stone circle still is a \
small pool. Somehow you feel very relaxed here, maybe it would be a good \
idea to rest for a while."

#define NIGHT_LONG ""
#define MOON_LONG ""


#define COLORS ({"clear", "light blue", "blue", "dark blue", "very dark"})

int sps_in_pool;

int add_sp(int n) {
    sps_in_pool += n;
    if(sps_in_pool<0) sps_in_pool = 0;
    if(sps_in_pool > MAX_SPS_IN_POOL) sps_in_pool = MAX_SPS_IN_POOL;
    save_object(SAVE_FILE);
    return sps_in_pool;
}

void decrease_sps() {
    sps_in_pool--;
    if(sps_in_pool < 0) sps_in_pool = 0;
    save_object(SAVE_FILE);
    call_out(#'decrease_sps, DECR_DELAY);
}

int query_sp() { return sps_in_pool; }


string
my_long_desc(string id, object who, status night) {
    // thought it would be a good idea to have several descs, but
    // I maybe will write them later...
    /*
	if(night){
	    if(nature()->query_moon())
		return MOON_LONG;
	    return NIGHT_LONG;
	}
    */
    return DAY_LONG;
}


string
pool_desc(string id, object who, status night) {
    int n;
    /*
	if(night) {
	    if(nature()->query_moon())
		return "Moonlight reflects from the surface of the pool, \
    making it sparckle like a blue diamond.";
	    return "The water in the pool is very dark, making it \
    impossible to see what's under the surface.";
	}
	return "You see a reflection of the blue sky at the surface of the pool.";
    */
    n = sps_in_pool / 700;

    if(n>=sizeof(COLORS)) n = sizeof(COLORS)-1;
    return "The water of the pool is " + COLORS[n] + ".";
}

void create_virtual() {
    X = 10;
    Y = 2;
    set(ROOM_WD, WD_OUTDOORS);
    set(NO_CLEANUP);
    set(PREVENT_TELEPORT);
    set_light_level(LT_LIGHTS);
    set_short("A circle of stones");
    set_long(#'my_long_desc);

    set_items(([
	({"stone", "stones"}): "There's eight large stones in a circle \
around you. At the northmost stone is carved some symbols, but otherwise \
the stones don't bear any marks that they would have been shaped by any \
other forces than the mother nature herself.",
	({"symbol", "symbols", "carvings"}): "Carved at the stone to the north \
is a human figure, probably a priest, pointing something at the pool.",
	// Isn't that a bit silly desc?

	({"maple", "tree"}): "Despite it's large size, that tree doesn't seem \
to be too old yet. Maybe it hasn't been so long after all, when these \
gardens were abandoned. Or could it be the water of that little pool, that \
has made the tree look so ageless?",
	"altar": "There's not much left of the altar. Just some mossy stones \
and pieces of wood scattered around the maple.",
	// hmm... if you cleaned the stones from moss, you could find
	// something interesting...

	({"forest", "trees", "woods"}): "The forest looks ancient. There's thick \
layers of moss and beard lichen on the tall trees, and you can't see any signs \
that beings other than animals had lived here for centuries.",

	({"pool", "water"}): #'pool_desc,
      ]));

    set_commands(([
	"point" : "empty_cmd",
      ]));

    set_virtual_exits(([
	"north":({0,-1}),
	"northeast":({1,-1}),
	"east":({1,0}),
	"southeast":({1,1}),
	"south":({0,1}),
	"southwest":({-1,1}),
	"west":({-1,0}),
	"northwest":({-1,-1}),
      ]));

    //set_distant_look(1);
    set(SKIP_EXITS);

    restore_object(SAVE_FILE);
    call_out(#'decrease_sps, DECR_DELAY);
}


status listen_cmd(string str)
{
    this_player()->tell_me("You hear birds singing and the quiet \
murmur of trees.");
    return 1;
}


status
empty_cmd(string s) {
    string what, target;
    object ob;
    int amount;

    if(!s) return 0;
    if(sscanf(s, "%s at %s", what, target)!=2){
	if(sscanf(s, "%s with %s", target, what)!=2)
	    return notify_fail("Point what at what?\n"),0;
    }
    ob = present(what, TP);
    if(!ob) return notify_fail("You don't have anything called that.\n"),0;
    if(target != "pool") return notify_fail(sprintf("You point %s \
at %s, but nothing happens.\n", what, target)),0;
    if(!ob->is_priest_staff())
	return notify_fail("You can't empty that to the pool!\n"),0;
    if(ob->query_owner() != TP)
	return notify_fail("But that staff is not yours.\n"),0;

    amount = ob->query_cur_sps();
    ob->add_sps(-amount);
    amount -= random(amount/4);
    add_sp(amount);

    tell_here(":%<me.capname>% point%<me.ending_s>% %<me.possessive>% \
staff at the pool. The surface of the pool turns deep blue, but returns \
back to normal as %<me.name>% lower%<me.ending_s>% %<me.possessive>% \
staff.",0,0,0,TP,0,0);
    write_file(PRIEST_DIR "log/moonwell",sprintf("%s: %s +%d sps.\n",
	ctime(time()), capitalize(TP->query_real_name()), amount));
    return 1;
}


// for meditate:
status query_priest_moonwell() { return 1; }

begin_hallu(object me) {
    int t;

    if(!me) return;
    me->tell_me("Wow, the sky's yellow!");
    t = sps_in_pool / 100;
    if(!t) return;
    if(t>40) t = 40;
    me->add_condition(C_HALLUCINATING, 5 + t);
}


status
drink_cmd(string s, object who) {
    if(!s || (s!= "water" && s != "from pool"))
	return notify_fail("Drink what?\n"),0;

    who->drink_soft(5);
    who->tell_me("You take a sip from the pool.");
    tell_here(":%<me.capname>% drinks from the pool.",0,0,who,who,0,0);
    call_out(#'begin_hallu, 3+random(3), this_player());
    return 1;
}
