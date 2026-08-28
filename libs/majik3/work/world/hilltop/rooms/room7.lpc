// DATE        : Sun Feb  8 20:20:50 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : yorkaturr

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Western hill path");
  set_long (
    "You are climbing up a gradually rising hill. You are almost ce"
  + "rtain this road leads to the legendary Hilltop of Gods.");

  add_exit ("southeast", ROOM_PATH + "room6");
  add_exit ("east", ROOM_PATH + "room8");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
