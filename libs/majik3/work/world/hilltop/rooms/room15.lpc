// DATE        : Sat Feb 14 19:20:04 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : namhas

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("The General Store");
  set_long (
    "You are standing in the general store of hilltop. You can 'buy"
  + "', 'sell' and 'list' items here.");

  add_exit ("southwest", ROOM_PATH + "room2");

  set_outdoors (1);
  set_light (1);
  add_object (MONSTER_PATH + "shopkeeper");
}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
