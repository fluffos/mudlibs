#include <school.h>

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("LPC Examples");
  SetIntLong("From this room you can go to all of the different areas "
    "we have example files for. The files are sorted into categories, "
    "rooms, npcs, combat, objects...\n"
    "Please be patient while we add more files. :-)\n");
  AddExit("npcs", ROOMS("npc") );
  AddExit("combat", EXCOMBAT("room1") );
//  AddExit("rooms", ROOMS("room") );
}
