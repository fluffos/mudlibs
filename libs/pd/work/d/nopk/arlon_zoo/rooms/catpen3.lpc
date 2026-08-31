#include <petzoo.h>
#include <std.h>
inherit "std/room";

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "The cat pen");
    set("long", "You are in a large pen.  There are quite a few kittens "+
      "jumping around the area.");
    set_exits( ([ "east" : ROOMS"catpen4", 
	"south" : ROOMS + "catpen2" ]) );
    set_listen("default", "Mewing and purring come from all directions.");
}
void reset() {
    int num_of_mobs = random(MAX_MOB_IN_ZONE)+1;
    int i;
    ::reset();
    if(!present("monster")) {
	for (i=0;i<num_of_mobs;i++){
	    new(MOB"kitten")->move(this_object());
	}
    }
}
