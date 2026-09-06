#include "path.h"
#include <rooms.h>
#include <properties.h>
#include <money.h>
#include <combat.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a small chamber");
  SetIntLong("You're in a small cavern.\n\
There is a sign at the wall.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"chamber","small chamber","room","small room",
  "cave","cavern","small cave","small cavern"}),QueryIntLong());
  AddDetail(({"floor","ground","walls","wall","ceiling"}),
"You see nothing special.\n");
  AddDetail("sign","Something is written on it.\n");
  AddReadMsg("sign","For seven and eight reverse tiny and late.\n");
  AddExit("south","./deep7");
  AddItem("/std/npc",REFRESH_HOME,
    ([P_NAME:"troll",
      P_SHORT:"a troll",
      P_LONG:"This is a nasty, bad smelling troll.\n",
      P_AGGRESSIVE:1,
      P_LEVEL:12,
      P_HP:170,
      P_RACE: "troll",
      P_ALIGN:-200,
      P_AC:7,
      P_HANDS:({({"its left hand",0,13}),({"its right hand",0,14})}),
      P_ITEMS_REFRESH:({
	({"/obj/money",REFRESH_REMOVE,
	  (["Money":MONEY_DEMON->CreateMoney((random(20)+10),({"copper"}))]),0}),
	({"/std/armour",REFRESH_REMOVE|REFRESH_FUNC,
          ([P_SHORT:"troll gloves",
	    P_LONG:"You see nothing special about the gloves.\n",
	    P_AC:1,
	    P_SIZE:PSIZE_LARGE,
	    P_RESET_QUALITY: 89,
	    P_ARMOUR_TYPE:AT_GLOVES,
	    P_VALUE:200,
	    P_WEIGHT:1000,
	    P_IDS:({"gloves"}),
	    P_ADS:({"troll"})]),"wieldme",0}) })
      ]));
}
