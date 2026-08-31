#include <petzoo.h>
#include <std.h>
inherit "std/room";

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "The goat pen");
    set("long", "This is a large pen that houses animals for petting.  Several "+
      "goats graze on pretty much anything they can find here.");
    set_exits( ([ "east" : ROOMS"goatpen" , "south" : ROOMS"goatpen3" ]) );
    set_listen("default", "The sounds of goats bleating are all around you.");
    set_smell("default", "Smells of goats and animal feed fill the air.");
}
void reset() {
    int num_of_mobs = random(MAX_MOB_IN_ZONE)+1;
    int i;
    ::reset();
    if(!present("monster")) {
	for (i=0;i<num_of_mobs;i++){
	    new(MOB"goat")->move(this_object());
	}
    }
}
