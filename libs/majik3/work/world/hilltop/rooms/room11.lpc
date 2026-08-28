// DATE        : Sun Feb  8 19:35:39 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : yorkaturr

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Cave entrance");
  set_long (
    "You are standing before the mouth of a dark and opaque cave. Y"
  + "ou feel reluctant to enter, but you can't help but wonder wha"
  + "t might be in there... Maybe you should explore further?");

  add_exit ("cave", ROOM_PATH + "cave1");
  add_exit ("northwest", ROOM_PATH + "room10");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
