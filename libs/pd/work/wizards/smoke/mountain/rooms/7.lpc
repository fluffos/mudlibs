#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("The ground is slanted more steep here than at the top of the mountain."
          " Interesting rocks make up the walls, which stretch to the mountains "
          "peak. Ice ferns can be seen growing randomly from the ground.");
    set_items(([
({"rocks", "walls"}) : "The walls are made up of some pretty cool rock formations."
	" A nest can be seen high up on the northern wall.",
({"nest"}) : "A nest can be seen high up on the northern wall. A couple of baby"
	" eagles can be seen poking their head out of the nest, chirping wildly."
	" They're probably waiting for their mother to return with some lunch.",
({"fern", "ferns"}) : "The arctic ferns can grow in the most extreme temperatures."
	" The plant is all white and appears very brittle.",
({"slant"}) : "The ground slants pretty steeply here. To the southeast, the"
	"slope leads down, while going northeast goes up a bit."	
    ]));
    set_exits( ([ 
       "north" :  "/wizards/smoke/mountain/rooms/6",
       "southeast" :  "/wizards/smoke/mountain/rooms/8"
    ]) );
}
void reset() {
    if(!present("goat"))
        new("/wizards/smoke/mountain/monsters/mtroll")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mtroll")->move(this_object());
}
