inherit"std/room";

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <rooms.h>

int called;

void create() {
  ::create();
  SetIntShort("Small yard");
  SetIntLong(
"A small yard surrounded by houses. The entrance to a pub is to the east, "+
"and a dark and gloomy alley leads to the north. To the south Pub Alley "+
"ends in Main Street. To the west you see Ali Bubu's carpet market.\n");
  AddExit("north", "./pubstreet");
  AddExit("east",  "./pub");
  AddExit("west","./cmarket");
  AddExit("south", "./vill_road1");
  SetIndoors(0);
//  AddItem(MONSTER("beggar"),REFRESH_HOME);
  /* the grippemonster will be removed when drannor opens 
     it is removed by Cadra 06-07-95 due to strange changes there */
//  AddItem("/d/drannor/common/monsters/grippemonster",REFRESH_DESTRUCT);
  AddItem("/std/weapon",REFRESH_REMOVE,
    ([P_SHORT:"knife",
      P_WC:3,
      P_WEAPON_TYPE:WT_KNIFE,
      P_DAM_TYPE:DT_PIERCE,
      P_WEIGHT:300,
      P_VALUE:8,
      P_QUALITY:78,
      P_SIZE:PSIZE_NORMAL,
      P_LONG:"A simple small knife.\n",
      P_IDS:({"knife"}),
      P_ADS:({"a","simple","small"}),
      P_NUMBER_HANDS:1]));
}
