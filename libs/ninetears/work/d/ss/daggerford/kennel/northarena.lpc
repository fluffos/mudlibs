inherit "std/room";
#include "path.h"

void setup() 
  {
  set_light(100);
  set_short("Arena Hallway");
  set_long("This is part of the circular hallway around the arena. To "+
           "the south you can see the arena where people gather to "+
           "watch animals engage in battle.  To the southwest you "+
           "see a training area where animals are prepared to enter "+
           "into the arena fights.  The hallway continues to circle "+
           "around to the southeast. There is a painting on the wall "+
           "here.\n");

  add_alias("picture", "painting");

  add_item("painting", "This painting depicts Havek, a large Bull "+
                       "Mastiff who died tragically just moments "+
                       "after regaining the title of Arena Champion "+
                       "for the second time.\n");

  add_exit("south", ROOM +"arena", "corridor");
  add_exit("southwest", ROOM +"training", "corridor");
  add_exit("southeast", ROOM +"arenahall", "corridor");

 }
