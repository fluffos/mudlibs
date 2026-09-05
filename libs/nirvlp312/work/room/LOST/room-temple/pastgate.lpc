#include "room.h"

init() {
     ::init();
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
}

look(str) {
  if (!str) return 0;
  if (str == "at temple"||str=="at walls"||str=="at granite walls"
     ||str=="at wall"||str=="at granite wall"){
    write("The thirty foot high walls block your view of the temple\n"+
      "and anything going on inside. they are of a quality construction\n"+
      "with anti-climbing spikes located near the top.\n");
    return 1;
  }
  if (str == "at gate" ||str=="gate"||str=="menacing bronze gate"){
    write("Beyond this small well secured gate all you can see the eastroad.\n");
    return 1;
  }
  if (str == "at arch" || str == "arch") {
    write("The arch reads in old carved letters above it, P A L A D I N S.\n");
    return 1;
  }
   return 0;
}    

THREE_EXIT(
         "room/temple/1","west",
         "room/temple/path","east",
         "room/temple/pal","north",
"Temple",
    "You are just beyond the gate into the temple. The walls are high and like\n"+
    "a maze. The sounds of weapons clashing can still be heard coming from \n"+
    "further within. Immediately to the north a small archway leads into a \n"+
    "a small open area. The maze like passage weaves north then to the west.\n",1)
