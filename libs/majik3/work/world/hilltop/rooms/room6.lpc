// DATE        : Sun Feb  8 19:49:11 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : yorkaturr

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Crossing");
  set_long (
    "You are standing on a landing between two rather high hills. T"
  + "he thin hill-path separates into two even smaller ones, of wh"
  + "ich the other one leads west, to what appears to be a very hi"
  + "gh hill, maybe even the legendary Hilltop of Gods, while the "
  + "other continues east.");

  add_exit ("southwest", ROOM_PATH + "room5");
  add_exit ("northeast", ROOM_PATH + "room10");
 add_exit ("northwest", ROOM_PATH + "room7");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
