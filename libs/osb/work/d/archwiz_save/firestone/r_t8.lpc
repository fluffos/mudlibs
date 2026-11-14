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
  AddExit("west","./r_t2");
  AddItem("/std/npc",REFRESH_HOME,
    ([P_NAME: "ogre",
      P_SHORT: "a cave ogre",
      P_LONG: "This is a huge cave ogre. He looks very heroic.\n",
      P_RACE: "ogre",
      P_AGGRESSIVE: 1,
      P_LEVEL: 17,
      P_SIZE:PSIZE_LARGE,
      P_HANDS: ({ ({"left hand",0,12}),({"right hand",0,15}) }),
      P_AC: 6,
      P_GENDER: 1,
      P_ALIGN: -500,
      P_ADS: ({"cave","huge","heroic"}),
      P_ITEMS_REFRESH: ({ ({"/std/armour",REFRESH_REMOVE|REFRESH_FUNC,
	([P_SHORT: "a black chain mail",
	  P_LONG:
"A very heavy black chain mail. It is covered with scratches "
"and old dried blood and it smells awful.\n",
	  P_IDS: ({"chain","chainmail","mail","armour"}),
	  P_ADS: ({"black","heavy","very heavy","chain"}),
	  P_ARMOUR_TYPE:AT_MAIL,
	  P_VALUE: 3000,
	  P_WEIGHT: 25000,
	  P_AC: 4,
	  P_SIZE:PSIZE_LARGE,
	  P_RESET_QUALITY: 50]),"wearme",0}),
      ({"/std/armour",REFRESH_REMOVE|REFRESH_FUNC,
	([P_SHORT: "a black helmet",
	  P_LONG: "A very big and heavy black helmet with scratches on it.\n",
	  P_ADS: ({"black","very big","big","heavy"}),
	  P_ARMOUR_TYPE:AT_HELMET,
	  P_VALUE: 100,
	  P_WEIGHT: 2500,
	  P_SIZE:PSIZE_LARGE,
	  P_RESET_QUALITY:56,
	  P_AC:1]),"wearme",0}) }) ]) );

}
