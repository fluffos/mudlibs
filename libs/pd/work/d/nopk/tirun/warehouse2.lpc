//Made using Room generator by Nightshade
//stormbringer for PD
#include <std.h>
#include <tirun.h>
inherit ROOM;
int rt, ra;
void init() {
    ::init();
    add_action("move_crate", "move");
    add_action("search_trash", "search");
}
void create() {
    ::create();
    set_short("warehouse");
    set_properties( (["light" : 2, "night light" : 2, "indoors" : 1]) );
    set_listen("default", "The building groans and settles.");
    set_smell("default", "It smells of dust and age.");
    set_long("An old abandoned warehouse.  Trash lies in heaps upon the floor.  Old "
      "delapidated crates are stacked along the east wall.  Glass from the "
      "windows is scattered about in the piles of trash.  The building looks "
      "as if it might collapse at anytime. The door is to the east. ");
    set_exits( (["east" : ROOMS+"nhaven7"
      ]) );
    set_items( ([ "floor" : "Old cracked weathered boards.",
	"crates" : "Wooden crates that used to hold valuable goods. One of the crates looks sturdier than the others.",
	"crate" : "There are skid marks on the floor around the crate.",
	"trash" : "Piles of discarded items. There looks like there might be something in the trash.",
	"glass" : "Glass shards scattered throught the trash.",
	"windows" : "Glassless frames looking outside."
      ]) );
}
void reset() {
    ::reset();
    rt = 1;
    ra = 1;
}
int move_crate(string str) {
    if(!str) {
	notify_fail("Move what?\n");
	return 0;
    }
    if(str != "crate") {
	notify_fail("You can't move that!\n");
	return 0;
    }
    if(this_player()->query_stats("strength") < 6) {
	message("info", "The crate will not budge.", this_player());
	return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" moves the crate easily.", this_object(), ({ this_player() }));
    message("info", "You find a hidden switch that unlocks the crate.", this_player());
    message("info", "The crate glides open easily.", this_player());
    if(ra==1) {      
	write("A rat jumps out from behind the crate attacking you!");
	say("A rat jumps out from behind the crate attacking "+(string)this_player()->query_cap_name()+"!");
	if(!present("rat"))
	    new(MOB"rat")->move(this_object());
	ra=0;
	return 1;
    }
    call_out("go_crate", 15);
    return 1;
}
int search_trash(string str) {
    if(!str) {
	notify_fail("Search what?\n");
	return 0;
    }
    if(str != "trash") {
	notify_fail("You don't find anything.\n");
	return 0;
    }
    if(rt==0) {
	notify_fail("You don't find anything.\n");
	return 0;
    }
    if(rt=1) {      
	write("A rat jumps out of the trash attacking you!");
	say("A rat jumps out of the trash attacking "+(string)this_player()->query_cap_name()+"!");
	new(MOB"rat")->move(this_object());
	rt=0;
	return 1;
    }
}
void go_crate() {
    message("info", "The crate moves back into position.", all_inventory(this_object()));
}
