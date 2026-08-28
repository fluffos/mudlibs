// DATE        : Sun Nov  2 21:28:29 1997
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : shinael

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("At the west gate, inside the city");
  set_long (
    "You've arrived to the west gate of Silvercreek which means you"
  + " were lucky or you're a criminal, for the west gate is mainly"
  + " used by the criminals and ruffians. Nothing has been done to"
  + " get rid of the scum in here, yet the adamantium gates of the"
  + " city will hold against the real enemy. Lamps are hanging on "
  + "the both sides of the gate, giving some light during the nigh"
  + "t time. A door leads south to a guard house. In east you can "
  + "see some kind of a bazaar.");

  add_exit ("south", ROOM_PATH + "wgatehouse");
  add_exit ("east", ROOM_PATH + "bazaar1");
  add_exit ("west", ROOM_PATH + "outwgate");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
