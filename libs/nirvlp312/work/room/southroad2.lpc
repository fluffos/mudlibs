#include "room.h"

init() {
     ::init();
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
}

look(str) {
  if (!str) return 0;
  if (str == "at building"){ 
    write("The old brick building has a faded sign, slanted due to a\n"+
    "broken mounting point reading 'Groc's Gym'.\n");
  return 1;
  }
  return 0;
}

#undef EXTRA_RESET
#define EXTRA_RESET no_castle_flag = 1;
THREE_EXIT("room/southroad1","north",
       "players/boltar/sprooms/gym", "east",
        "room/southroad3", "south",
	   "South road",
"Southroad is a worn cobblestone road that runs north and south through\n"+
"the village, The business district appears to be overtaking other\n"+
"land uses here and the road continues to the south or north to the\n"+
"village's main road.  There is a beat up looking brick building to\n"+
"east.\n",1)

