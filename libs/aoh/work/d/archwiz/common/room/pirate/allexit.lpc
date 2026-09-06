#include <properties.h>
#include <rooms.h>
#include "path.h"
inherit "/std/room";

create() {
  ::create();
    SetIntLight(40);
    SetIntShort("A room with 8 exits");
   SetIntLong(
"You are in a small room with eight exits. "
"In each one of those is a pulsating magic field.\n");
  AddDetail(({"room","small room"}),QueryIntLong());
  AddDetail(({"exit","exits"}),
"You see magic fields all around you except for the "
"southwestern exit. It seems to lead into a dark cave.\n");
  AddDetail(({"field","fields","magic field","magic fields"}),
"Blue shimmering light pulsates like a field.\n");
  AddDetail(({"light","blue light","shimmering light",
  "blue shimmering light"}),
"It looks magical.\n");
  AddDetail(({"cave","dark cave","southwest exit","southwestern exit"}),
"The cave looks deep and dark.\n");
  AddDetail(({"walls","wall","corner","corners"}),
"At each wall and in each corner there is a magic field.\n");
  AddDetail(({"floor","ground","ceiling"}),"You see nothing special.\n");
  AddExit(({"south","southeast","west"}),CITY("shop"));
  AddExit(({"north","northwest"}),CITY("church"));
  AddExit(({"east","northeast"}),CITY("adv_guild.1"));
  AddExit("southwest","./deep1");
  AddItem("/std/thing",REFRESH_REMOVE,
    ([P_SHORT:"a medium sized ruby",
      P_LONG:"You see a sparkling ruby. It looks valuable.\n",
      P_ADS:({"red","sparkling","a","valuable"}),
      P_IDS:({"ruby","gem","stone"}),
      P_WEIGHT:1,
      P_VALUE:100]));
}
