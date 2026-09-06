#include <properties.h>
#include <rooms.h>

inherit "/std/room";

create() {
   ::create();
   AddExit("west","./transp");
   AddExit("north","./r_t2");
   AddExit("east","./r_chest");
   AddExit("south","./r_t10");
   SetIntShort("You are in a corridor.");
   SetIntLong(
"You are in a corridor. There is a loudspeaker in the ceiling. You hear an "
"announcement:\n"
"  Attention, attention! Some of the creatures we have "
"caught in the course of our expedition in Nightfall "
"broke out of their cages. Be careful! Most of them "
"are very dangerous!\n");
  SetIndoors(1);
}
