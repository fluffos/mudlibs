inherit "/room/room";

#include "actions.h"

// PROTOTYPES
string extra_look();

void reset(int arg){
  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "Behind the mill";
  long_desc =
    "You have arrived at a pond behind Hobbe's mill. You can still "+
    "see part of the wheel that powers the mill. " + @@extra_look@@ +
    "The area is quite "+
    "beautiful with all the trees and bushes. There are some large "+
    "stones lying on the ground.\n";

  items = ({
    "stones","Some heavy grey stones",
    "ground","You see some heavy stones lying in the grass",
    "grass","The fresh grass looks beautiful",
    "sky","You see the blue sky",
    "bushes","They line the path",
    "path","This path appears to lead north",
    "pond","The stream collects here forming a pond",
    "water","It looks cool and refreshing"
  });

  dest_dir = ({
    HOBBE + "path4", "north",
  });
}

string extra_look() {
  if((HOBBE + "path4")->query_has_solved())
    return "The wheel is currently turning, allowing the mill to work. ";
  return "The wheel is not moving, preventing the mill from working "+
    "properly. ";
}

