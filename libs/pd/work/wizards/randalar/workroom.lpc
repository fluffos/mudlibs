#include <locations.h>
//      from the Nightmare mudlib
//      an example workroom for new immortals

#include <std.h>
#include "/wizards/randalar/std/mydefs.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The Void");
    set_night_long("%^BOLD%^%^BLACK%^The absolute nothingness of the void surrounds everything.\n"
                   "All senses are numb, nothing to see, nothing to hear, nothing\n"
                   "to smell, nothing to feel, nothing to taste.  The only things\n"
                   "here are what is brought.  Directions almost seem useless,\n"
                   "with everything the same, day or night.%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^The absolute nothingness of the void surrounds everything.\n"
                 "All senses are numb, nothing to see, nothing to hear, nothing\n"
                 "to smell, nothing to feel, nothing to taste.  The only things\n"
                 "here are what is brought.  Directions almost seem useless,\n"
                 "with everything the same, day or night.%^RESET%^");
//    set_day_long("It is day outside.\nA new immortal works here.\n");
    set_exits( ([
      "up"    : "/wizards/randalar/workroom",
      "down"  : "/wizards/randalar/workroom",
      "north" : "/wizards/randalar/workroom",
      "south" : "/d/nopk/tirun/square",
      "east"  : "/wizards/randalar/workroom",
      "west"  : "/wizards/randalar/workroom",
//    "hall" : "/d/standard/adv_main",
    ]) );
//  set_smell("default", "It smells like a new immortal in here.");
//  set_listen("default", "You hear the sounds of code creation.");
}
