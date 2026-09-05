#include "room.h"
init() {
     ::init();
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
}

look(str) {
  if (!str) return 0;
  if (str == "at grass"||str=="at rocky fields" ||str=="at field" || 
      str=="at fields") {
    write("The grassy field is full of large and small rocks alike.\n"+
         "making the land unusable for farming, grazing, and difficult\n"+
         "to travel across.\n"); 
    return 1;
  }
  if (str == "at mountains" || str=="at cliff") {
    write("The mountains rise steeply to the north.\n");
     return 1;
  }
  return 0;
}


TWO_EXIT("room/sunalley2","west",
         "room/eastroad3","east",
"Sun alley",
"Sun alley runs east-west along the edge of mountains and cliffs to\n"+
"the north. The south side of the road is just rocky fields difficult\n"+
"to travel on. A lush green grass grows between the rocks obscuring\n"+
"most of them from view until right on top of them.\n",1)

