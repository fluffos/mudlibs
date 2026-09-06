#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include <combat.h>

inherit "/std/room";
 
create() {
  ::create();
  SetIntShort("In the engine-room");
  SetIntLong("You are in the engine room of the starship Enterprise.\n");
  SetIndoors(1);
  AddExit("up","./r_t10");
  AddItem("/std/npc",REFRESH_HOME,
    ([P_NAME: "Klingon",
      P_SHORT: "a Klingon spy",
      P_LONG:
"The Klingon spy seems to be trying to sabotage the warp engines.\n",
      P_RACE: "human",
      P_IDS: ({"spy","klingon"}),
      P_ADS: ({"klingon"}),
      P_LEVEL: 3,
      P_HANDS: ({ ({"left hand",0,6}),({"right hand",0,6}) }),
      P_AC: 1,
      P_GENDER: 1,
      P_ALIGN: -200,
      P_CHAT_CHANCE: 5,
      P_CHATS: ({
"Klingon says: The enterprise will explode when they go into warp drive!\n",
"The klingon spy murmurs: Ha-ha!\n",
"Klingon says: The Empire will reward me for destroying the Enterprise!\n",
"Klingon says: That engineer never knew what hit him! HA_HA!\n",
"Klingon murmurs: Locking the First Officer in the closet was child's play!\n",
      }),
      P_ITEMS_REFRESH:({
	({"/std/weapon",REFRESH_REMOVE|REFRESH_FUNC,
	  ([P_SHORT: "a small screwdriver",
  	    P_IDS: ({"weapon","screwdriver"}),
	    P_ADS: ({"small","a"}),
	    P_SIZE:PSIZE_NORMAL,
	    P_LONG: "This once belonged to Mr. Sulu.\n",
	    P_WC: 2,
	    P_RESET_QUALITY:90,
	    P_WEIGHT: 50,
	    P_VALUE: 8,
	    P_DAM_TYPE:DT_PIERCE,
	    P_WEAPON_TYPE:WT_KNIFE,
	    P_NUMBER_HANDS: 1]),"wieldme",0})})]));
}
