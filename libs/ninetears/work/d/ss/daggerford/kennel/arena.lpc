inherit "std/room";
#include "path.h"

void setup() {
  set_light(100);
  set_short("Fighting Arena");
  set_long("This is the where owners bring their animals to engage "+
           "in battle.  The ground in the center of the arena is "+
           "very worn and stained with blood from previous fights. "+
           "There are many exits which all leave the arena.\n");

  add_exit("north", ROOM +"northarena", "corridor");
  add_exit("south", ROOM +"southarena", "corridor");
  add_exit("east", ROOM +"eastarena", "corridor");
  add_exit("west", ROOM +"westarena", "corridor");

 }
