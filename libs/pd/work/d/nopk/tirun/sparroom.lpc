//Made using Room generator by Nightshade
//Storm
#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Sparring Hall");
    set_properties( (["light" : 3, "night light" : 2, "indoors" : 1]) );
    set_listen("default", "The sound of weapons clashing can be heard.");
    set_long("The Sparring Hall was built to train in various forms of fighting.  The room is large, with weapons of all sorts displayed in racks around the room.  To the south is a sparring dummy.  The Fighter hall is up.");
    set_exits( (["up" : ROOMS+"fighter/fighter_join"
	,"south" : ROOMS+"sparroom2"
	,"out" : ROOMS+"swganthus"
//	,"east" : ROOMS+"swganthus"
      ]) );
    set_items( ([ "racks" : "Different sized frames which weapons sit on."
	,"weapons" : "Various weapons from around the realms."
      ]) );
}
