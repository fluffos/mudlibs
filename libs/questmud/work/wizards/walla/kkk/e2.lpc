#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

TWO_EXIT("wizards/walla/kkk/1", "north",
         "wizards/walla/area/jercs", "south",
         "At the entrance of a Klavern",
         "You are on a rocky road leading north and south.\n" +
         "Mountain sides rise high above you by both sides of the road.\n", 1)

extra_reset() 
  set_req("north");
 }

query_req() {
  if(this_player()->query_level() < 42 || this_player()->query_level() > 84 ||
        this_player()->query_race() == "orc" || this_player()->query_race() == "troll"
       || this_player()->query_race() == "dwarf" || this_player()->query_race() == "ent"
       || this_player()->query_race() =="halfling"
       || this_player()->query_race() == "gnome" || this_player()->query_race() =="drow")
    write("A guard pops out and says 'You're not of the right race, or level. Come back later
scmuck.\n");
    return 1;
  }
