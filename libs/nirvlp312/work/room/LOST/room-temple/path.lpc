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
  if (str == "at gate" ||str=="bronze gate"||str=="menacing bronze gate"){
    write("Beyond this small well secured gate all you can see is \n"+
      "more of the granite wall. The enterance path takes several turns\n"+
      "through a walled passageway to prevent people from peering\n"+
      "inside.\n");
    return 1;
  }
   return 0;
}    

TWO_EXIT("room/eastroad1","east",
         "room/temple/pastgate","west",
"Temple",
    "Off the west side of east road, the gate of the temple stands before you.\n"+
    "It is just open enough to let a person pass through it.  The walls obscure all\n"+
    "vision of the temple itself. You can hear the clashing of weapons from beyond\n"+
    "the temple's high granite walls, and menacing bronze gate.\n", 1)
