#include "room.h"

init() {
     ::init();
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
}

look(str) {
  if (!str) return 0;
  if (str == "at station" || str=="at police station") {
   write("The old brick and stone police station has seen better days.\n"+
    "as well as the motel across the street. The stone archway reads\n"+
    "simply 'POLICE' above the opening.\n");
   return 1;
  }
  return 0;
}

#undef EXTRA_RESET
#define EXTRA_RESET no_castle_flag = 1;
THREE_EXIT("room/vill_road3","north",
       "room/police", "west",
        "room/southroad2", "south",
	"South road",
"Southroad is a worn cobblestone road that runs north and south through\n"+
"the village, The business district appears to be overtaking other\n"+
"land uses here and the road continues to the south or north to the\n"+
"village's main road.  There is a police station to the west and a\n"+
"motel to the east.\n", 1)
