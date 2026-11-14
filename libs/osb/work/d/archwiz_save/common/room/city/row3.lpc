#include "path.h"
#include <combat.h>
#include <rooms.h>
#include <properties.h>

inherit "/std/room";


create() {
   ::create();
   SetIntShort("Skid Row");
   SetIntLong(
"You are in the worst part of town, you actually find yourself looking over "
"your shoulder a few times! To the north you can escape to the better parts of "
"Nightfall. There are not so many leatherguys around like here.\n");
    SetIndoors(0);
    AddExit("north","./boul4");
    AddExit("east","./row4");
    AddExit("west","./row2");
    AddExit("south","./forest5");
    AddItem("/std/npc",REFRESH_HOME,4,
      ([P_NAME: "Leatherguy",
	P_SHORT: "a leatherguy",
	P_LONG:
"This is a young man fully dressed in black leather clothes. He looks strong "
"and dangerous.\n",
      P_IDS: ({"leatherguy","guy","human","man"}),
      P_GENDER: 1,
      P_HP: 66,
      P_ADS: ({"young","leather"}),
      P_LEVEL: 3,
      P_AC: 3,
      P_HANDS: ({ ({"left hand",0,9}),({"right hand",0,9}) }),
      P_WIMPY: 20,
      P_RACE: "human",
      P_ITEMS_REFRESH: ({
       ({"/std/armour",REFRESH_REMOVE|REFRESH_FUNC,
	([P_SHORT: "a worn out leather jacket",
	  P_LONG: 
"This jacket has scratches all over. It has been used for motorbiking in "
"former times.\n",
	  P_AC: 2,
	  P_IDS: ({"jacket","armour","armor"}),
	  P_ADS: ({"black","leather","worn out","a","the"}),
	  P_WEIGHT: 2500,
	  P_VALUE: 80,
	  P_RESET_QUALITY: 55,
	  P_ARMOUR_TYPE:AT_MAIL,
	  P_SIZE:PSIZE_NORMAL]),"wearme",0 }) }) ]) );
    AddItem("/std/thing",REFRESH_HOME,
      ([P_SHORT:"an interesting sign",
	P_LONG:
"It is a wooden pointer. It points west and bears the words 'Newbie Park' "
"in large friendly letters.\n",
        P_IDS:({"sign","pointer"}),
	P_ADS:({"a","an","interesting","wooden"}),
        P_NOGET:1,
	P_READ_MSG:"To the Newbie Park.\n"]));
}
