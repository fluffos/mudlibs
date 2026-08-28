// DATE        : Mon Feb  9 17:46:09 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : yorkaturr

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Hill path");
  set_long (
    "You are walking down a hill path which leads away from Hilltop"
  + " Village to a hill where there seems to be a forest.");

  add_exit ("south", ROOM_PATH + "room13");
  add_exit ("northwest", ROOM_PATH + "room2");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
