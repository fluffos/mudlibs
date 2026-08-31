#include <petzoo.h>
#include <std.h>
inherit "std/room";

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "The mouse house");
    set("long", "This is a big building housing quite a few little mice.  They are "+
      "scurrying all over the place.");
    set_exits( ([ "south" : ROOMS"mousehouse" ]) );
    set_listen("default", "Sounds of mice squeaking can be heard all around you.");
}
void reset() {
    int num_of_mobs = random(MAX_MOB_IN_ZONE)+1;
    int i;
    ::reset();
    if(!present("monster")) {
	for (i=0;i<num_of_mobs;i++){
	    new(MOB"mouse")->move(this_object());
	}
    }
}
