#include <petzoo.h>
#include <std.h>
inherit "std/room";

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "A llama pen");
    set("long", "This is a large pen that houses animals for petting.  Several "+
      "baby llamas wander about here.");
    set_exits( ([ "south" : ROOMS"llamapen3" ,
	"west" : ROOMS"llamapen" ]) );
    set_smell("default", "Smells of llamas and animal feed fill the air.");
}
void reset() {
    int num_of_mobs = random(MAX_MOB_IN_ZONE)+1;
    int i;
    ::reset();
    if(!present("monster")) {
	for (i=0;i<num_of_mobs;i++){
	    new(MOB"llama")->move(this_object());
	}
    }
}
