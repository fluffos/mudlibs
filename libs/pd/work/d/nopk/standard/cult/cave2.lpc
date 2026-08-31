#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "Inside of the cave");
    set("long",
	"The cave comes to a wall south. A passage penetrates into the rocky "
	"ground, leading down to the next floor below this one. Water drips onto "
	"the rock ground from a few crack in the ceiling of the cave."
    );
    set_items(([
	"cave" : "A damp, old cave.",
	"passage" : "It goes into the dark chambers of the cave.",
	"water" : "Drip.... Drip.. Drip.",
    ]));
    set_exits(([
	"north" : ROOMS"cult/cave1",
	"down"  : ROOMS"cult/cave3",
    ]));
}

void reset() {
 ::reset();
   if (!present("punk")) {
     new(ROOMS "cult/mob/punk")->move(this_object());
   }
}
