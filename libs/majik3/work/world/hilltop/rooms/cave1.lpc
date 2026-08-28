// DATE        : Sun Feb  8 19:07:31 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : yorkaturr

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Cave");
  set_long (
    "You are in a murky cave, or at least what seems to be the begi"
  + "nning of one. A sinister blackness prevents you from seeing a"
  + "nything to the north, where the cave continues deeper into th"
  + "e Hilltop caverns. Eerie light is emanating from the south, w"
  + "here there is an apparent exit to the outerworld.");

  add_exit ("north", ROOM_PATH + "cave2");
  add_exit ("out", ROOM_PATH + "room11");

  add_sound ("You could've sworn you heard something.");

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
