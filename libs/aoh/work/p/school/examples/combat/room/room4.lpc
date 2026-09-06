/*
** Defence examples, room 4
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
  SetIntShort("Example room 4");
  SetIntLong("In this room you will meet Orgo the giant. Orgo is "
    "aggressive but will only attack with a chance of 40%. He wears "
    "a cloak made of animal hides that gives a special bonus to "
    "giants. If Orgo's HP drop below 20 in a fight he will run away.\n");
  SetIndoors(1);
  SetBright(20);
  AddExit("west","./room3");
  AddItem(NPC("giant"),REFRESH_DESTRUCT);
    // if your npc has a whimpy level or otherwise tends to walk away
    //   on its own, take care not to add it with REFRESH_REMOVE or
    //   you will have your area flodded with npc in no time. Better
    //   use REFRESH_DESTRUCT or REFRESH_HOME depending on the npc's
    //   purpose.
}
