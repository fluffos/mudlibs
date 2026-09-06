#include "path.h"
#include <properties.h>
#include <rooms.h>
inherit "/std/npc";

create () {
 if (::create()) return 1;
 SetName("rat");
 SetRace("rat");
 SetShort("a rat");
 SetIds(({"rat","animal"}));
 SetAds(({"sewer","a","brown"}));
 SetLong ("A sewer rat. It has a brown fur. It's length is about one foot.\n");
 SetLevel(3);
 SetInt(1);
 SetDex(18);
 SetGender(GENDER_NEUTER);
 SetAttribute("MagicDefence",10);
 SetAggressive(1);
 SetAttackChance(2);
 SetHands(({ ({"sharp teeth",0,8}), ({"tail",0,3}) }));
 AddItem("/std/thing",REFRESH_REMOVE,
   ([P_SHORT:"a black stone",
     P_LONG:"It's just a simple black stone.\n",
     P_IDS:({"stone","gem","rock","black_stone"}),
     P_ADS:({"simple","a","black"}),
     P_WEIGHT:20,
     P_VALUE:1,
     P_NOSELL:1]));
}
