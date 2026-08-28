// DATE        : Tue Feb 10 15:28:20 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : yorkaturr

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Forest path");
  set_long (
    "You are in a lush, green forest. The merry singing of starling"
  + "s can be heard from a distance and it is only surpassed by th"
  + "e wind whistling in the willows. The forest seems to get more"
  + " and more dense when moving south along the path. In the nort"
  + "h there awaits some pretty hard-looking territory with severa"
  + "l hills and ridges. You can spot a small settlement there as "
  + "well.");

  add_exit ("south", "/world/y286x194");
  add_exit ("northwest", ROOM_PATH + "room13");

  set_outdoors (4);
  set_no_monster (1);

}

// You should REMOVE all lines below this line if you are adding special
// stuff to this file by hand. Otherwise scary things can happen.

query_redit ()
{
  return 12;
}
