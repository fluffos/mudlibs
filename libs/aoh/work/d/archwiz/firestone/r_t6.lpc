#include <combat.h>
#include <rooms.h>;
#include <properties.h>
#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("In a corridor");
  SetIntLong("You are in a corridor.\n");
  SetIndoors(1);
  AddExit("south","./r_t7");
  AddExit("east","./r_t4");
  AddItem("/std/npc",REFRESH_HOME,
    ([P_NAME: "ogre",
      P_SHORT: "an ogre",
      P_LONG:
"The ogre looks very angry about meeting you. He raises his big, ugly hands "
"to grab and eat you. On his clothing you see the mark of a white hand.\n",
      P_RACE: "ogre",
      P_SIZE:PSIZE_LARGE,
      P_AGGRESSIVE: 1,
      P_LEVEL: 13,
      P_HANDS: ({ ({"left hand",0,20}),({"right hand",0,20}) }),
      P_AC: 10,
      P_GENDER: 1,
      P_ALIGN: -300,
      P_ITEMS_REFRESH:({ ({"/std/armour",REFRESH_REMOVE|REFRESH_FUNC,
	([P_SHORT: "a black mask",
	  P_LONG:
"A very big and heavy black helmet with sergants mark on it.\n",
	  P_IDS: ({"mask","helmet"}),
	  P_ADS: ({"big","very big","heavy","black"}),
	  P_ARMOUR_TYPE:AT_HELMET,
	  P_VALUE: 200,
	  P_WEIGHT: 2500,
	  P_AC: 1,
	  P_SIZE:PSIZE_LARGE,
	  P_RESET_QUALITY:60]),"wearme",0}),
      ({"/std/armour",REFRESH_REMOVE|REFRESH_FUNC,
	([P_SHORT: "a black platemail",
	  P_LONG:
"A very heavy black platemail. It is covered with scratches and old dried "
"blood and it smells awful.\n",
	  P_ARMOUR_TYPE:AT_MAIL,
	  P_VALUE: 5000,
	  P_WEIGHT: 40000,
	  P_AC: 5,
	  P_RESET_QUALITY: 45,
	  P_SIZE:PSIZE_LARGE,
	  P_IDS: ({"platemail","mail","plate","armour"}),
	  P_ADS: ({"black","heavy","very heavy"}) ]),"wearme",0}) }) ]) );
}
