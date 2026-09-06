/*
** Defence examples, room 2
**
** Author: Analena@Nightfall, 10feb97
** Update:
*/

#include <rooms.h>

inherit "/std/room";

#define NPC(x) "/p/school/examples/combat/npc/" x

varargs void create()
{
  ::create();
  SetIntShort("Example room 2");
  SetIntLong("In this room you will meet Bodo, an aggressive orc who is "
    "equipped with a wooden club, a chain mail and rusty boots.\nNote "
    "that although Bodo is aggressive he won't attack wizards (unless "
    "their wizmode is turned off). This is standard behaviour for all "
    "npcs and can't be changed.\n");
  SetIndoors(1);
  SetBright(20);
  AddExit("south","./room1");
  AddExit("east","./room3");
  AddItem(NPC("orc"),REFRESH_REMOVE);
    // if Bodo walks out of the room he will be cloned anew even if the
    //   old Bodo still exists in another room.
}
