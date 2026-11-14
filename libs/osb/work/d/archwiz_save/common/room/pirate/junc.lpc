#include "path.h"
#include <moving.h>
#include <rooms.h>
#include <properties.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a junction");
  SetIntLong(
"You're at a junction. Choose wisely. "
"A sign is mounted at the northern wall.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail("sign","Something is written on it.\n");
  AddDetail("junction",QueryIntLong());
  AddDetail(({"northern wall"}),"A sign is mounted there.\n");
  AddDetail(({"walls","wall"}),"A sign is mounted at the northern wall.\n");
  AddDetail(({"ceiling","floor","ground"}),
"It is muddy.\n");
  AddDetail(({"mud","dirt"}),"Just dirt.\n");
  AddReadMsg(({"sign"}),
"  Dragon's Lair: west.\n"
"  Living food will be welcome.\n"
"  (Return to your lovely cell)\n"
"  (Or die .....)\n");
  AddExit("south","./way2");
  AddExit("east","./junce");
  AddExit("west","./juncw");
  AddItem("/std/thing",REFRESH_REMOVE,
    ([P_SHORT:"golden bracelet",
      P_LONG:"It looks valuable.\n",
      P_VALUE:300,
      P_WEIGHT:100,
      P_IDS:({"bracelet"}),
      P_ADS:({"golden"})]));
}
