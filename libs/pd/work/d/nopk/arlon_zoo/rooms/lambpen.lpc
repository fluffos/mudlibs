#include <petzoo.h>
#include <std.h>
inherit "std/room";

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "The lamb pen");
    set("long", "You are in a large pen housing quite a few lambs.  They stand patiently"+
      " as the many visitors pet them.  The main path through the zoo is back to the north.");
    set_exits( ([ "east" : ROOMS"lambpen2", 
	"north" : ROOMS"zoopath15" ,
	"south" : ROOMS"lambpen4" ]) );
    set_listen("default", "The scattered sounds of lambs baaing emminate from everywhere.");
}
void reset() {
    int num_of_mobs = random(MAX_MOB_IN_ZONE)+1;
    int i;
    ::reset();
    if(!present("monster")) {
	for (i=0;i<num_of_mobs;i++){
	    new(MOB"lamb")->move(this_object());
	}
    }
}
