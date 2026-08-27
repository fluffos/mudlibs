inherit "std/room";
#include "path.h"

void setup() 
  {
  set_light(100);
  set_short("Training Area");
  set_long("This is the training area within the dog fighting arena.  "+
           "Here you see various animals being trained by their "+
           "owners to be vicious killers in the arena.\n");

  add_alias("animal", "animals");
  add_alias("owner", "owners");

  add_item("animal", "All of the animals are involved in various "+
                     "training and conditioning exercises to "+
                     "build stamina and learn better fighing "+
                     "techniques.\n");

  add_item("owner", "The owners take pride in training their "+
                    "faithful pets.  They hope their animals "+
                    "will win them a fortune in the betting arena.\n");

  add_exit("southwest", ROOM +"westarena", "corridor");
  add_exit("northeast", ROOM +"northarena", "corridor");

 }
