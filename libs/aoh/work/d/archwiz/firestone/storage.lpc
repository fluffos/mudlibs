#include <rooms.h>
#include "path.h"
#include <properties.h>

inherit "/std/room";

int get(string str) {
  if (!present("watchdog")) return 0;
  write("The dog snaps at your fingers!\n");
  return 1;
}

int pet(string str) {
  if (!str) return 0;
  if (!present("watchdog")) return 0;
  if ((str != "dog") && (str != "watchdog")) return 0;
  write("The dog snaps at your fingers!\n");
  return 1;
}

create() {
  ::create();
  SetIntShort("You are in the storage room of the castle.\n");
  SetIntLong("You are in the storage room of the castle.\n");
  SetIndoors(1);
  AddRoomCmd(({"get","take"}),#'get);
  AddRoomCmd("pet",#'pet);
  AddExit("west","./entr");
  AddExit("up","./space");
  AddItem("/std/npc",REFRESH_HOME,
    ([P_NAME: "watchdog",
      P_SHORT: "a huge watchdog",
      P_LONG: "You see a black nose, black eyes, black fur, white teeth.\n",
      P_RACE: "dog",
      P_AGGRESSIVE: 1,
      P_LEVEL: 2,
      P_IDS: ({"dog","watchdog"}),
      P_ADS: ({"huge","black"}),
      P_HANDS: ({ ({"teeth",0,6}),({"teeth",0,6}) }),
      P_AC: 1,
      P_GENDER: 1,
      P_ALIGN: -30]) );
  AddItem("/obj/bag",REFRESH_REMOVE,
    ([P_SHORT: "a brand new knapsack",
      P_LONG: "This knapsack looks unused.\n",
      P_IDS: ({"bag","knapsack","sack"}),
      P_ADS: ({"brand new","new","unused"}),
      P_WEIGHT: 100,
      P_MAX_WEIGHT: 5000,
      P_VALUE: 40]));
}
