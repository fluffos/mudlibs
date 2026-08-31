#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "Stepping inside a cave");
    set("long",
	"The stone walls of the cave close in very closely to each other. Two "
	"passageways are connected to this room in the cave. Once passage "
	"is north to the mouth of the cave, and the second goes south, deeper "
	"into the cave."
    );
    set_items(([
	"walls" : "They make you a bit dizzy.",
	"passageways" : "North-south right through the cave.",
	"cave" : "A spooky old cave."
    ]));
    set_exits(([
	"north" : ROOMS"cult/ent",
	"south" : ROOMS"cult/cave2",
    ]));
}

void reset() {
 ::reset();
   if (!present("extremist")) {
     new(ROOMS "cult/mob/extremist")->move(this_object());
   }
}
