/* source file -- Storage Room */
#include "path.h"

inherit "/std/storeroom";

void setup()
{
  set_short("Storage Facility");
  set_long("This room is quite ordinary except for "+
    "the quantities of stores kept here.  Guild "+
    "members must obviously come here and just "+
    "drop common and inexpensive equipment right "+
    "on the floor.  The walls are lined with "+
    "shelves and chests containing many items.\n");
  set_light(70);
  set_zone("guild");

  add_item( ({ "stores", "items", "equipment" }),
    "Among the stores, there is sacks of flour, casks "+
    "of ale, chords of firewood, bolts of common "+
    "cloth, torches, even barrels of water, and "+
    "other such supplies.\n");

  add_exit("west", ROOM + "hall2", "door");
}

 
