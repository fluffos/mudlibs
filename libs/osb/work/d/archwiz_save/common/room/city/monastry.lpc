/* made by RoomMaker V0.94 (c) Sique 12/1992 */

#include "path.h"

// BEGONE inherit MONASTRY;
inherit "/std/room";

create()
{
  ::create();
  SetIntShort("the monastry ein Nightfall City");
  SetLong( // BEGONE was SetMonastryLong
"You are standing in a hall. It's the foyer of a monastery. "
"You see some pictures of the Saints at the wall. "
"To the west you can leave the monastery.\n"
    );
  AddDetail(({"pictures","saints","picture","saint"}),
  "You see pictures of Saints you don't know.\n");
  AddExit("west","./shouse");
}
