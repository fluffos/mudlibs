#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("The ground is slanted more steep here than at the top of the mountain."
          " Interesting rocks make up the walls, which stretch to the mountains "
          "peak. A nest can be seen on the northern wall high up on a rock.");
 set_listen("default", "Baby birds can be heard chirping from the nest above.");
    set_items(([
({"rocks", "walls"}) : "The walls are made up of some pretty cool rock formations."
	" A nest can be seen high up on the northern wall.",
({"nest"}) : "A nest can be seen high up on the northern wall. A couple of baby"
	" eagles can be seen poking their head out of the nest, chirping wildly."
	" They're probably waiting for their mother to return with some lunch.",
({"slant"}) : "The ground slants pretty steeply here. To the south, the slope "
	"leads down, while going east goes up a bit."	
    ]));
    set_exits( ([ 
       "east" :  "/wizards/smoke/mountain/rooms/5",
       "south" :  "/wizards/smoke/mountain/rooms/7"
    ]) );
}
void reset() {
    if(!present("goat"))
        new("/wizards/smoke/mountain/monsters/eagle")->move(this_object());
        new("/wizards/smoke/mountain/monsters/eagle2")->move(this_object());
        new("/wizards/smoke/mountain/monsters/eagle3")->move(this_object());
}
