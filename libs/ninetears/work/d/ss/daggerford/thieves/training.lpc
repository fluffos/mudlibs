/* source file -- Training Hall */
#include "path.h"

inherit "/std/room";

void setup()
{
  set_short("Training Hall");
  set_long("This large training facility comprises "+
    "a network of scaffolds, tightropes, elevated "+
    "platforms, free standing walls, and tables of "+
    "locks and lockpicks.  There are a few people "+
    "honing their skills physically, while others are "+
    "reading manuals of stealth.  Occasionally, a "+
    "master may be seen giving advice and lessons.\n");
  set_light(70);
  set_zone("guild");

  add_item( ({"scaffolds", "platforms", "walls", "ropes" }),
    "The gym equipment is well used and well maintained.\n");
  add_item( ({"locks", "lockpicks"}),
    "The locks and lockpicks are too worn to be actually "+
    "implemented, so they are used for practice instead.\n");
 
  add_exit("east", ROOM + "hall3", "door");
}

