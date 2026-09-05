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
  if (str == "at mountains" || str=="at cliff" || str=="at gap") {
    write("The mountains rise steeply to the north and west. To the\n"+
       "west is small opening but it appears impassable from fallen\n"+
       "rocks and trees.\n");
     return 1;
  }
  return 0;
}

ONE_EXIT("room/sunalley1","east",
"Sun alley",
"Sun alley runs east-west along the edge of mountains and cliffs to\n"+
"the north. There are also mountains to the west blocking all but a\n"+
"small gap. The south side of the road is just rocky fields difficult\n"+
"to travel on. A lush green grass grows between the rocks obscuring\n"+
"most of them from view until right on top of them.\n",1)

