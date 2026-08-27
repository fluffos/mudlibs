inherit "std/room";
#include "path.h"

void setup() {
  set_light(100);
  set_short("Arena Hallway");
  set_long("This is a large hallway which circles around the arena "+
           "to the north.  The hallway curves northeast where you "+
           "see an area in which you can buy an animal to enter "+
           "into the arena fights.  To the northwest are the "+
           "kennels.\n");

  add_item("arena", "The arena looks like it has seen many "+
                    "battles.\n");
  add_item("kennels", "The kennels look like they haven't been "+
                      "cleaned in quite a while.\n");

  add_exit("north", ROOM +"arena", "corridor");
  add_exit("south", ROOM +"entrance", "corridor");
  add_exit("northeast", ROOM +"sellroom", "corridor");
  add_exit("northwest", ROOM +"kennel", "corridor");

 }
