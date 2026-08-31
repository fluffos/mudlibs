#include <petzoo.h>
#include <std.h>
inherit "std/room";

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "A coral");
    set("long", "This is a large coral.  Several ponies canter and trot around you.  "+
      "Glancing at the outer fence you happen to see little kids getting rides as well."+
      "  The main petting zoo is back to the west.");
    set_exits( ([ "west" : ROOMS"zoopath12",
	"east" : ROOMS"coral4",
	"south" : ROOMS"coral2" ]) );
    set_smell("default", "Smells of hay fill the air.");
    set_listen("default", "Occasional neighing can be heard from all directions.");
}
void reset() {
    int num_of_mobs = random(MAX_MOB_IN_ZONE)+1;
    int i;
    ::reset();
    if(!present("monster")) {
	for (i=0;i<num_of_mobs;i++){
	    new(MOB"pony")->move(this_object());
	}
    }
}
