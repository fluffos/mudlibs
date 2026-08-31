#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "indoors" : 1, "light" : 2, "night light" : 1, ]) );
    set_short( "the Duergar city" );
    set_long("The Shaman training hall of Duergar is a large and crowded room, filled with everything from books and potions, to crystal balls and various plants.  There is a large open space as well, for practicing spellwork.  Many shamans study here in the day.");
set_exits(([
"out" : ROOMS"duergar/63",

]));
    set_items( ([
"books":"The books are all very old and fragile looking.",
"table":"The table is rickety and scratched up, but it still stands fine.",
"crystal balls":"The shamans use the crystal balls to gaze into the future.",
"plants":"It seems that the shamans are collecting plants for alchemy.",
]) );
    set_smell("default",  "The smell of smoke is a bit overpowering.");
    set_listen("default", "There is quite a lot of noise echoing from the inside of the cave.");
if(random(100) < DIRAN_ROOM_CHANCE){
        if(!present("dshaman"))
          new(MOB "dshaman")->move(this_object());
          new(MOB "dshaman")->move(this_object());
          new(MOB "dshaman")->move(this_object());
          new(MOB "dshaman")->move(this_object());
}
}