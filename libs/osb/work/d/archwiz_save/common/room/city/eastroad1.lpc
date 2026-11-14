 /* made by Sique using RoomMaker V0.992 (c) Sique 2/1993 */

#include "path.h"

// BEGONE inherit HOUSEROAD;
inherit "/std/room";

create()
{
  ::create();
  SetIntShort("East road");
  SetIntLong("East road runs north-south. A new Folk Club lies northwest.\n");
  AddExit("east","./healer");
  AddExit("north","./eastroad2");
  AddExit("south","./vill_shore");
  AddExit("northwest","./folkclub");
  AddDetail(({"club","folk club"}),"A small one story wooden building\n");
  SetIndoors(0);
}
