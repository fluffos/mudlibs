// DATE        : Sun Nov  2 21:22:17 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Bazaar, near the west gate");
  set_long (
    "You've arrived to the west gate of Silvercreek. The gate is in"
  + " west. The surrounding area is some kind of a bazaar. The baz"
  + "aar continues to east and north. In south it joins Blood alle"
  + "y. A short distance to the east you can see a tavern sign. Pe"
  + "ople here are likely to be outlaws and criminals. The bazaar "
  + "is a place for gathering information and some coins, in case "
  + "some decent people dare to come here.");

  add_exit ("south", ROOM_PATH + "blood4");
  add_exit ("north", ROOM_PATH + "bazaar3");
  add_exit ("east", ROOM_PATH + "bazaar2");
  add_exit ("west", ROOM_PATH + "underwgate");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
