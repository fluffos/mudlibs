// DATE        : Mon Feb  9 18:03:28 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : yorkaturr

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Look point");
  set_long (
    "You are walking along a hill path which has been laid between "
  + "the forest and Hilltop Village. A crude hut, apparantly a gua"
  + "rd house of some sort, has been built next to a large birch t"
  + "ree, whose mighty shadow ominously embraces the ground.");

  add_exit ("southeast", ROOM_PATH + "room14");
  add_exit ("north", ROOM_PATH + "room12");
  add_exit ("hut", ROOM_PATH + "hut1");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
