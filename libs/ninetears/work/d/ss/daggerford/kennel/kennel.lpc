inherit "std/room";
#include "path.h"

void setup() 
  {
  set_light(100);
  set_short("Kennels");
  set_long("This is the kennel area within the dog fighting arena.  "+
           "The walls are lined with cages containing various "+
           "animals which await their turn to enter the arena.\n");

  add_alias("cage", "cages");
  add_alias("animal", "animals");

  add_item("cage", "The cages look like they haven't been cleaned "+
                    "out in quite a long time.\n");
  add_item("animal", "Each of these animals looks pretty vicious "+
                      "and eager to enter the arena.\n");

  add_exit("northwest", ROOM +"westarena", "corridor");
  add_exit("southeast", ROOM +"southarena", "corridor");

 }
