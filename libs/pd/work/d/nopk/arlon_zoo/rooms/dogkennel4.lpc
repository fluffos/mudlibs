#include <petzoo.h>
#include <std.h>
inherit "std/room";

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "The dog kennel");
    set("long", "You are in a dog kennel There are several puppies playing throughout"+
      " the kennel.");
    set_exits( ([ "east" : ROOMS"dogkennel",
	"south" : ROOMS"dogkennel3"]) );
    set_listen("default", "The sounds of dogs yipping are all around you.");
}
void reset() {
    int num_of_mobs = random(MAX_MOB_IN_ZONE)+1;
    int i;
    ::reset();
    if(!present("monster")) {
	for (i=0;i<num_of_mobs;i++){
	    new(MOB"puppy")->move(this_object());
	}
    }
}
