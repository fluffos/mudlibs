
#include <properties.h>
#include <ansi.h>

#define AB(x)   ANSI_BOLD + x + ANSI_NORMAL


inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("room 2");
  SetIntLong(
   "The fog is not much thinner here, but the glowing light is marginally "
   "stronger.\n"
   "\n"
   "All rooms (locations in the MUD) have exits which lead to other "
   "rooms. Most exits are 'obvious', "
   "meaning that they will always appear at the bottom of the room "
   "description. Some are hidden, though; you will have to discover these "
   "exits for yourself.\n"
   " \n"
   "You can continue through the fog to the north.\n\n");

  AddExit("north","./room03");
  AddExit("south","./room01");

  Set(P_NOWAY_MSG, "The fog only becomes thicker in that direction. North "
    "would be a wiser choice. Or choose south to retrace your path.\n");


  SetIndoors(1);

}
