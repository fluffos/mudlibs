// DATE        : Sun Feb  8 19:38:12 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : yorkaturr

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Eastern hill path");
  set_long (
    "You are walking on the gently down sloping eastern hill path. "
  + "Looking back you can still see the T-junction of the paths at"
  + " a distance.");

  add_exit ("southwest", ROOM_PATH + "room6");
  add_exit ("southeast", ROOM_PATH + "room11");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
