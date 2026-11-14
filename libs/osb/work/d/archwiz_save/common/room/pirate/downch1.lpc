#include "path.h"
#include <money.h>
#include <combat.h>
#include <rooms.h>
#include <properties.h>

inherit "/std/room";

int say(string str) {
  tell_room(CITY("church"),"You hear voices from below your feet. "
"Exactly you hear someone saying: "+str+"\n");
}

create() {
  ::create();
  SetIntShort("You're directly below the church");
  SetIntLong(
"You're standing in an old dark room. Voices can be heard from above, but "
"you see no way to pass the ceiling but a staircase leads down into more "
"darkness.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"old room","room","dark room","old dark room"}),
QueryIntLong());
  AddDetail(({"voices","voice"}),
"The voices sound hollow.\n");
  AddDetail(({"ceiling","walls","wall"}),
"You see nothing special.\n");
  AddDetail(({"floor","ground"}),
"There is a staircase leading down.\n");
  AddDetail(({"stairs","stair","staircase"}),
"The staircase leads down.\n");
  AddDetail("darkness","Dark.\n");
  AddDetail(({"church","city church"}),"YOu must be directly below it.\n");
  AddNoise(({"voices","voice"}),"The voices sound hollow.\n");
  AddRoomCmd(({"say","saz"}),#'say);
  AddExit("down","./downch2");
  AddExit("south","./dark7");
  AddItem("/std/armour",REFRESH_REMOVE,
    ([P_SHORT:"cowboy hat",
      P_LONG:"A fine cowboy hat made of leather.\n",
      P_AC:1,
      P_ARMOUR_TYPE:AT_HELMET,
      P_VALUE:20,
      P_WEIGHT:1000,
      P_SIZE: PSIZE_NORMAL,
      P_QUALITY: 56,
      P_IDS:({"hat","helmet","helm"}),
      P_ADS:({"an","a","old","cowboy"})]));
  AddItem("/obj/money",REFRESH_REMOVE,
    (["Money":MONEY_DEMON->CreateMoney((random(3)+4),({"copper"}))]));
  AddItem("/obj/torch",REFRESH_REMOVE);
}
