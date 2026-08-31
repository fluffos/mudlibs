#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 2, "night light" : 1,
     "indoors" : 1, "house" : 1 ]));
   set_short("a kitchen");
   set_day_long("Daylight streams in through the single open window "
     "and the doorway to the south. Pots and pans litter the ground "
     "and area around the stove. A cat bowl and water dish have been "
     "set near the doorway.");
   set_night_long("The kitchen is pretty dark, with the exception of "
     "the moonlight that streams in from the single opened window. The "
     "doorway to the south leads into the main room of the house, in "
     "view of the garden. Pots and pans have been strewed all about, but "
     "are mostly hidden in the shadows of night. A cat bowl and water "
     "dish have been set carefully near the doorway.");
   set_items(([
     "dish" : "The water dish is filled about halfway with dirty water.",
     "bowl" : "The food bowl is empty, that means one unhappy kitty.",
     "doorway" : "It is the only exit in this room.",
     "light" : "The light streams in through the open window.",
     "window" : "It has been left ajar.",
     ({ "pots", "pans" }) : "Pots and pans are all over the place, it'll "
                            "be a lot of work for who ever has to clean "
                            "it all up."
   ]));
   set_exits(([ "south" : ROOMS"house1" ]));
}

void reset() {
 ::reset();
   if (!present("cat"))
     make(MOB"cat");
}
