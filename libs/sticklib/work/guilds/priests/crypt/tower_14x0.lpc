// 30-Jul-96 / Graah: If they kill the man, he doesn't always return
// at each reset! We don't want too much potions & drugs.

// 19-Feb-98 Chopin: Added a hatch that leads to the priest guild.

#include <areas.h>
#include AREA_TRISTEZA "DEFS.h"
#include <room_defs.h>
#include <living_defs.h>

inherit	TRISTEZA_ROOM_C;

#define ROOM_UNDER_US "/guilds/priests/crypt/virtual/under_tower"


status hatch_is_open;

status query_hatch_open() { return hatch_is_open; }

string hatch_desc() {
    return sprintf("The hatch is made of wood, but merges into the stone floor \
pretty well, especially because of the thick layer of dust. %s", 
      hatch_is_open ? "It is open." : "It is closed.");
}

string room_long_desc() {
    return sprintf("You are on the bottom of a tower. There is dust everywhere. \
%sThe tower hasn't been used since the great orc wars.",
      hatch_is_open ? "There is an open hatch on the floor. " : "");
}

void
create_room()
{
    ::create_room();
    set(ROOM_WD, WD_INDOORS);
    set_short("Tower bottom");
    set_long(#'room_long_desc);
    add_item("dust", "It's just ordinary dust.");
    add_item("hatch", #'hatch_desc);
    add_exit("up", CITY_DIR + "T_NE2");
    add_exit("southwest", CITY_DIR+"S13_1");
    //    add_monster("/players/sumppen/mon/black",0,5);
}

status search_cmd(string what) {
    if(hatch_is_open)
	return 0;

    this_player()->tell_me("You search the room for a while, and notice a \
hatch on the floor covered by a thick layer of dust.");
    return 1;
}

void open_hatch(status from_the_other_side) {
    hatch_is_open = 1;
    add_exit("down", ROOM_UNDER_US);
    ROOM_UNDER_US->add_exit("up", object_name());
    ROOM_UNDER_US->set_light_level(LT_DIM);
    if(from_the_other_side) {
	tell_here(({
	    "A hatch opens up on the floor, its hinges squeaking.",
	    "You hear something squeaking.",
	  }), ({LIV_CAN_SEE, LIV_CAN_HEAR}),
	  0,0,0,0,0);
	ROOM_UNDER_US->tell_here(({
	    ":%<me.capname>% push%<me.ending_es>% the hatch open.",
	    "You hear something squeaking.",
	  }), ({LIV_CAN_SEE, LIV_CAN_HEAR}),
	  0,0,this_player(),0,0);
    } else {
	tell_here(({
	    ":%<me.capname>% open%<me.ending_s>% a hatch on the floor. It squeaks \
on its hinges.",
	    "You hear squeaking like something was opened.",
	  }), ({LIV_CAN_SEE, LIV_CAN_HEAR}),
	  0,0,this_player(),0,0);
	ROOM_UNDER_US->tell_here(({
	    "Someone pulls the hatch open from the room above. It squeaks on \
its hinges.",
	    "You hear squeaking.",
	  }), ({LIV_CAN_SEE, LIV_CAN_HEAR}),
	  0,0,0,0,0);
    }
    // Let's close the hatch automatically so that all players wont find
    // this immediately
    call_out("close_hatch", 15, 1);
}


status open_cmd(string what) {
    if(what != "hatch") return 0;
    if(hatch_is_open) return notify_fail("But it is already open!\n"),0;
    open_hatch(0);
    return 1;
}

void close_hatch(status automagically) {
    hatch_is_open = 0;
    remove_exit("down");
    ROOM_UNDER_US->remove_exit("up");
    ROOM_UNDER_US->set_light_level(LT_DARKNESS);
    if(automagically) {
	tell_here(({
	    "The hatch closes with a bang!",
	    "The hatch closes.",
	    "You hear a bang!",
	  }), ({LIV_CAN_SEE|LIV_CAN_HEAR, LIV_CAN_SEE, LIV_CAN_HEAR}));
	ROOM_UNDER_US->tell_here(({
	    "The hatch closes with a bang!",
	    "The hatch closes.",
	    "You hear a bang!",
	  }), ({LIV_CAN_SEE|LIV_CAN_HEAR, LIV_CAN_SEE, LIV_CAN_HEAR}));
	// *sigh* had to write these messages twice
    }
    else {
	tell_here(({
	    ":%<me.capname>% close%<me.ending_s>% the hatch."
	  }), ({LIV_CAN_SEE}),0,0,this_player(),0,0);
	ROOM_UNDER_US->tell_here(({
	    ":%<me.capname>% close%<me.ending_s>% the hatch."
	  }), ({LIV_CAN_SEE}),0,0,this_player(),0,0);
    }
    remove_call_out("close_hatch");
}


status close_cmd(string what) {
    if(what != "hatch") return 0;
    if(!hatch_is_open) return notify_fail("But it is already closed!\n"),0;
    close_hatch(0);
    return 1;
}
