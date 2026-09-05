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
      "and anything going on inside. They are of a quality construction\n"+
      "with anti-climbing spikes located near the top.\n");
    return 1;
  }
  if (str == "at arch" || str == "arch") {
    write("The arch reads in old carved letters above it in an unknown alphabet.\n");
    return 1;
  }
   return 0;
}    

/*
TWO_EXIT("room/temple/pastgate","east",
         "room/temple/mnk","south",
         "Temple",
"You are just beyond the gate into the temple. The walls are high and like\n"+
"a maze. The sounds of weapons clashing can still be heard coming from\n"+
"further within. But there is no visible way to get there from here. Immediately\n"+
"to the south a small archway leads into a room of some sort. The maze like\n"+
"passage after a small jog to the south arch just seems to end. It is very loud\n"+
"as the sounds and outer dimensions indicate a much larger facility.\n",1)
*/
ONE_EXIT(
         "room/temple/pastgate","east",
"Temple",
    "You are just beyond the gate into the temple. The walls are high and like\n"+
    "a maze. The sounds of weapons clashing can still be heard coming from \n"+
    "further within. But there is no visible way to get there from here. Immediately\n"+
    "to the south a small archway leads into a room of some sort. The maze like\n"+
     "passage after a small jog to the south arch just seems to end.  It is very loud\n"+
    "as the sounds and outer dimensions indicate a much larger facility\n",1)
