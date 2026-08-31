#include <petzoo.h>
#include <std.h>
inherit "std/room";

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "The raccoon pen");
    set("long", "You're in a large pen with several raccoons foraging about."+
      "  The place as a bit of a foresty feel to it.  The main path through"+
      " the zoo is back to the east.");
    set_exits( ([ "north" : ROOMS"raccoonpen2", 
	"west" : ROOMS"raccoonpen4", 
	"east" : ROOMS + "zoopath7" ]) );
    set_smell("default", "There is a hint of a fresh pine in the air.");
}
void reset() {
    int num_of_mobs = random(MAX_MOB_IN_ZONE)+1;
    int i;
    ::reset();
    if(!present("monster")) {
	for (i=0;i<num_of_mobs;i++){
	    new(MOB"raccoon")->move(this_object());
	}
    }
}
