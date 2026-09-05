#include "room.h"

init() {
     ::init();
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
}

look(str) {
  if (!str) return 0;
  if (str == "at hotel"){
    write("The sign on the grand old hotel reads: The Hotel Time and Space.\n"+
     "It's a wood and brick structure, the first floor brick, the upper \n"+
     "ones in wood. The once colorful paint scheme is faded and peeling.\n");
    return 1;
  }
  if (str =="at bank") {
     write("The bank is a heavy stone building with an archway enterance.\n"+
      "On the arch, it is carved into the stone, BANK.\n");
     return 1;
  }
  return 0;
}

#undef EXTRA_RESET
#define EXTRA_RESET no_castle_flag = 1;
FOUR_EXIT("room/vill_road3","south",
  "players/boltar/sprooms/clothier", "northwest",
  "room/northroad2","north",
  "room/bank", "east",
  "Village road (Northroad)",
"Northroad is a worn cobblestone road that runs north and south through\n"+ 
"the village. The business district appears to begin here and the road\n"+
"continues to the north or south to the village's main road. There is a\n"+
"bank on the east side of the street and a clothing shop to the northwest.\n"+
"On the east side of the street to the north is a grand hotel that appears\n"+ 
"run down from age and overuse.\n", 1)
