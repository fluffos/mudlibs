inherit "std/room";
#include "path.h"

void setup() {
  set_light(100);
  set_short("Arena Hallway");
  set_long("This is a dimly lit area in the arena.  The mixture of "+
           "odors from the kennels which are southeast of here and "+
           "blood from the arena to the east isn't very pleasing to "+
           "your nose.  The northeast hallways leads off to "+
           "a training area where animals are prepared to enter "+
           "into the arena fights. "+
           "There is a painting on the wall here.\n");

  add_item("painting", "This painting shows a proud owner rewarding "+
                       "his faithful Saint Bernard after a vigorous "+
                       "training session.\n");
  add_item("kennels", "The kennels contain many animals in cages.\n");

  add_exit("east", ROOM +"arena", "corridor");
  add_exit("northeast", ROOM +"training", "corridor");
  add_exit("southeast", ROOM +"kennel", "corridor");

 }
