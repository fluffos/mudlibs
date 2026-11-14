#include "path.h"
#include <rooms.h>
#include <properties.h>
#include <combat.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("dead end");
  SetIntLong("You've arrived at a dead end. "
"There is a sign at the wall.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail("sign","You should read it.\n");
  AddDetail(({"room","dead end","end"}),QueryIntLong());
  AddDetail(({"floor","ground","ceiling","walls","wall"}),"You see nothing special.\n");
  AddReadMsg("sign","In all the land the fourth is and ...\n");
  AddExit("south","./m3");
  AddItem("/obj/torch",REFRESH_REMOVE);
  /* This bullet was for a Western miniquest. 
   * See also .../lair.c and nearsea.c
   */
  AddItem("/std/thing",REFRESH_REMOVE,
    ([P_SHORT:"a bullet",
      P_LONG:"This is a deadly looking bullet. An inscription is on it.\n",
      P_WEIGHT:10,
      P_VALUE:2,
      P_READ_MSG:"1879\n",
      P_IDS:({"bullet"})]));
  AddItem("/std/armour",REFRESH_REMOVE,
    ([P_SHORT:"a pirate's cloak",
      P_LONG:"There are pictures of fighting pirates on it.\n",
      P_AC:1,
      P_ARMOUR_TYPE:AT_CLOAK,
      P_VALUE:50,
      P_SIZE:PSIZE_NORMAL,
      P_QUALITY: 34,
      P_WEIGHT:2000,
      P_IDS:({"cloak","piratecloak"}),
      P_ADS:({"a","pirate's"})]));
}
