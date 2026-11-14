#include <rooms.h>
#include <combat.h>
#include <properties.h>
#include "path.h"

inherit "/std/room";
 
create() {
  ::create();
  SetIntShort("In a corridor");
  SetIntLong("You are in a corridor.\n");
  SetIndoors(1);
  AddExit("west","./r_scott");
  AddExit("east","./r_t8");
  AddExit("south","./r_t1");
  AddItem("/std/npc",REFRESH_HOME,
    ([P_NAME: "kobold",
      P_SHORT: "nasty kobold",
      P_LONG: "A nasty looking, scaly little creature with sharp teeth.\n",
      P_RACE: "kobold",
      P_SIZE:PSIZE_SMALL,
      P_ADS: ({"nasty looking","nasty","scaly little","little"}),
      P_IDS: ({"kobold","creature"}),
      P_LEVEL: 3,
      P_AGGRESSIVE:1 ,
      P_GENDER: 1,
      P_ALIGN: -300,
      P_HANDS: ({ ({"left hand",0,6}),({"right hand",0,6}) }),
      P_AC: 1,
      P_ITEMS_REFRESH:({ ({"/std/armour",REFRESH_REMOVE|REFRESH_FUNC,
        ([P_SHORT: "a small shield",
	  P_LONG: "A small shield made of iron.\n",
	  P_ADS: ({"small","iron"}),
	  P_VALUE: 100,
	  P_WEIGHT: 1000,
          P_RESET_QUALITY: 25,
          P_AC: 1,
	  P_ARMOUR_TYPE:AT_SHIELD,
	  P_NUMBER_HANDS: 1,
	  P_SIZE:PSIZE_SMALL]),"wearme",0}) }) ]) );
}
