#include "room.h"

init() {
     ::init();
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
}

look(str) {
  if (!str) return 0;
  if (str == "at statue"||str=="at buried head" ||str=="at crown" ||
      str == "at buried statue" || str == "at head" ||
      str == "at large statue" || str == "at large head" ) {
    write("The curvature of the shorline cliffs block sight of the\n"+
      "mysterous statue.\n");
    return 1;
  }
  if (str == "at drop" || str == "at sheer drop" || str=="at cliff") {
     write("A straight drop about eighty feet to the rocks and water\n"+
     "below.\n");
     return 1;
  }
  return 0;
}


TWO_EXIT("room/eastroad5","north",
         "room/eastroad3","south",
"East road",
"The East Road runs north-south parallel to the village shore. The\n"+
"sheer drop to the east is merely inches from the edge of the road.\n"+
"The road is coming towards it's north end and appears to be more.\n"+
"settled along this portion north of Sunalley.\n",1)

