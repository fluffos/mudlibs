inherit "std/room";
#include "path.h"

void setup() {
  set_light(100);
  set_short("Arena Hallway");
  set_long("You are in a dirty hall full of doors. " +
           "To the northwest you will find the main "+
           "fighting arena, this is obvious since you car hear screaming and "+
           "barking. You also hear barking and commands from the training " +
           "area to the north. The shop is to the northeast, and the buyers " +
           "training area to the east.\n" +
           "There is a trohpy case here which is kept nice and clean "+
           "comapred to the rest of this building.\n");

  add_alias("trophies", "case");

  add_item("case", "This case is filled with many trophies won by "+
                   "champion fighting dogs.\n");


  add_exit("southeast", ROOM +"eastarena", "corridor");
  add_exit("northwest", ROOM +"northarena", "corridor");

 }
