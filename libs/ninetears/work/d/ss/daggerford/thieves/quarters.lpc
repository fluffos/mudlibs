/* source file -- Thieves' Quarters */
#include "path.h"

inherit "/std/room";

void setup()
{
  set_short("Thieves' Quarters");
  set_long("These quarters are obviously for those who cannot "+
    "afford dwelling in any other place.  The walls are lined "+
    "with fold-down bunks and the floor is covered with straw-"+
    "filled cots.  The meager possessions of some folk are "+
    "placed carefully around the room.  They are worthless "+
    "to any other than their owners.  The room is fairly tidy "+
    "but dimly lit and the air is heavy with unwholesome "+
    "smells.\n");  
  set_light(70);
  set_zone("guild");

  add_item( ({"bunk", "bunks"}),
    "The bunks are no more than hinged platforms that are "+
    "chained to the wall at each end.  A thin mat on each "+
    "one provides little comfort to those that use them.\n");
  add_item( ({"cot", "cots", "beds"}),
    "The cots are covered with straw and a blanket.  They "+
    "are functional but not at all appeasing.\n");
  add_item( ({"possessions", "belongings"}),
    "You find absolutely nothing of interest or use.\n");

  add_exit("east", ROOM + "hall1", "door");
}

