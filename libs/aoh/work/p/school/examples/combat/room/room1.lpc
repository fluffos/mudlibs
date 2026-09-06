/*
** Defence examples, room 1
**
** Author: Analena@Nightfall, 10feb97
** Update:
*/

#include <rooms.h>                        // refresh-flags for AddItem

inherit "/std/room";

#define NPC(x) "/p/school/examples/combat/npc/" x
    // defining the directory where to find example-npcs

varargs void create()
{
  ::create();
  SetIntShort("Example room 1");
  SetIntLong("In this room you will meet Daniel, a non-aggressive "
    "human who is equipped with a simple short sword, wooden shield and "
    "leather armour.\n");
  SetIndoors(1);
  SetBright(20);
  AddExit("north","./room2");
  AddExit("south","/p/school/rooms/example");
  AddItem(NPC("human"),REFRESH_HOME);
    // Daniel will be moved back to this room during reset in case he
    //   walked out of the door.
}
