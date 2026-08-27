/* source file -- Meeting Room */
#include "path.h"

inherit "/room/admin/meeting";

void setup() {
  set_short("Meeting Area");
  set_long("This room is no room at all!  This is the surface!  The stars "+
    "gleam brightly overhead in the nightime sky.  The sound of "+
    "nocturnal insects and animals and the odor of a fresh dew are "+
    "brought by a cool breeze.   In the center of this small glade, a "+
    "campfire spews sparks into the atmosphere.  In front of it is an old "+
    "tree trunk.  Scattered around are rocks and boulders of small to "+
    "largish size.  Remarkably, the entrance is still there, but without "+
    "dimensions.\n");
  set_light(70);

  add_item("stars", "Some of them are winking.\n");
  add_item( ({"fire", "campfire"}), "For a large fire, it does not radiate "+
    "much heat.\n");
  add_item( ({"trunk", "tree trunk"}),
    "The tree trunk is old and worn.  A sign is written on the front "+
    "of it.  There is also a gnarled staff on it.\n");
  add_item( ({"rocks", "boulders"}),
    "The rocks are slightly round and are firmly embedded into the "+
    "ground.  Curiously, most all of them are flat or slanting on top.\n");
  add_item(({ "stick", "staff" }),
    "The staff looks notched and dented as if someone has "+
    "beaten everything in sight with it.  You could bang it around a "+
    "little maybe, it might help if you had it though.\n");
  log_bing = 0;
  sign = add_sign("A small sign with not much written on it.\n",
                  "There is no current chair of the meeting.\n");
  add_exit("portal", ROOM + "hall4", "door");
}
