#include "room.h"

init() {
     ::init();
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
}

look(str) {
  if (!str) return 0;
  if (str == "at building" || str == "at sign") { 
     write("This building appears to be the place where people leave their\n"+
     "children to be cared for while they are away.\n");
     return 1;
  }
  if (str == "at smithy" || str == "at smithy shop") {
     write("You can see a small empty room inside and hear the banging\n"+
       "of metal from within. There is large amount of smoke rising \n"+
       "the chimney.\n");
     return 1;
   }
  return 0;
}

#undef EXTRA_RESET
#define EXTRA_RESET no_castle_flag = 1;
THREE_EXIT("room/northroad2","south",
          "players/boltar/sprooms/weaponsmith", "east",
          "players/boltar/sprooms/daycare-unf","west",
	   "Village road (Northroad)",
"The worn, cobblestone Northroad comes to an end here. There are shops\n"+
"to either side of the street.  A worn old smithy shop with a sign \n"+
"reading 'Equipment Repaired' to the east. A modern looking red-brick\n"+
"building decorated with crayon signage reading 'Daycare center' to\n"+
"the west."+
"\n",1)
