// DATE        : Mon Feb  9 18:10:11 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : yorkaturr

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Intersection");
  set_long (
    "You are standing in the middle of the Hilltop Village central "
  + "square, which acts as an intersection between all the major r"
  + "oads and paths in the vicinity. To your east you can spot"
  + " a clean-looking inn, whose smoking chimney gives it a very c"
  + "ozy touch. There's also a post office to the north, but it do"
  + "es not look that popular considering the village is rather sm"
  + "all. The road to your west goes up a rather high hill, while "
  + "the road southeast is gently down-sloping in nature.");

  add_exit ("southeast", ROOM_PATH + "room12");
  add_exit ("north", ROOM_PATH + "room3");
  add_exit ("east", ROOM_PATH + "room1");
  add_exit ("northwest", ROOM_PATH + "bank");
  add_exit ("northeast", ROOM_PATH + "room15");
  add_exit ("west", ROOM_PATH + "room4");

  set_outdoors (4);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
