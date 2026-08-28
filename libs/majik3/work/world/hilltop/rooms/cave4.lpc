// DATE        : Sun Feb  8 19:31:57 1998
// DESCRIPTION : A generic room object created using LPC redit 1.2
// CODER       : yorkaturr

#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Hole");
  set_long (
    "You are standing somewhere very deep in the Hilltop Caverns. I"
  + "t is very, very dark here, however you are able to notice a l"
  + "arge hole on the ground which is even darker than the rest of"
  + " the room. You could try your luck by jumping in the hole, bu"
  + "t it is impossible to decipher whether there's a bottom or no"
  + "t.");

  add_exit ("southeast", ROOM_PATH + "cave2");

}

init_room ()
{
  add_action ("do_jump", "jump");
}

do_jump (string str)
{
  if (!str)
      return 0;

  write ("You jump to hole.\n");
  EXPLORE_D->teleport(THIS);
  return 1;
}
