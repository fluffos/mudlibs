#include <money.h>
#include <combat.h>
#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cavern");
  SetIntLong("You're in a dark and cold cavern. "
"There is a sign at the wall.\n");
  AddDetail("sign","There is something written on it.\n");
  AddDetail(({"cave","cavern","dark cave","dark cavern",
  "cold cave","cold cavern","dark and cold cave","dark and cold cavern"}),
QueryIntLong());
  AddDetail(({"walls","wall","floor","ground","ceiling"}),
"You don't see anything special.\n");
  AddReadMsg("sign","To give him four... he'll not be poor.\n");
  AddExit("east","./deep14");
  AddExit("west","./deep5");
  AddExit("north","./deep2");
  AddItem("/std/npc",REFRESH_HOME,
    ([P_SHORT:"a cave lurker",
      P_LONG:"The monster seems to lurk around here.\n",
      P_NAME:"lurker",
      P_LEVEL:8,
      P_HP:320,
      P_ALIGN:0,
      P_HANDS:({ ({"its left claw",0,7}),({"its right claw",0,10}) }),
      P_AC:12,
      P_AGGRESSIVE:0,
      P_GO_CHANCE:1,
      P_WIMPY:300,
      P_ITEMS_REFRESH:({ ({"/obj/money",REFRESH_REMOVE,
	(["Money":MONEY_DEMON->CreateMoney(random(20)+4,({"copper"}))]),0}),
	({"/std/weapon",REFRESH_REMOVE|REFRESH_FUNC,
	  ([P_SHORT:"a small jeweled sword",
	    P_LONG:"Many precious stones are fastened to it.\n",
	    P_WC:7,
	    P_WEAPON_TYPE:WT_SWORD,
	    P_DAM_TYPE:DT_SLASH,
	    P_NUMBER_HANDS:1,
	    P_VALUE:200,
	    P_WEIGHT:8000,
	    P_IDS:({"sword"}),
	    P_ADS:({"small","jeweled","a"}) ]),"wieldme",0}) }) ]) );
}
