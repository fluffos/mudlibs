/*
** Defence examples, room 3
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
  SetIntShort("Example room 3");
  SetIntLong("In this room you will meet Valery, a young elven maiden. "
    "Valery is a friend of all living beings but a fierce enemy of "
    "vampires.\nValery is aggressive against vampires only and carries "
    "some special equipment against vampires.\n");
  SetIndoors(1);
  SetBright(20);
  AddExit("east","./room4");
  AddExit("west","./room2");
  AddItem(NPC("elf"),REFRESH_DESTRUCT);
    // Valery won't be recloned in this room unless she gets killed or
    //   otherwise destructed, regardless of where she is. If you can't
    //   find her and she isn't recloned on resetting this room, don't
    //   hesitate to xload the room, it is only an example room for
    //   wizards anyway ;)
}
