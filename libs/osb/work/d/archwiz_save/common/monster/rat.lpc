#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit "/std/npc";

create () {
 if (::create()) 
   return 1;
 SetName("rat");
 SetRace("rat");
 SetShort("a rat");
 AddId(({"rat","animal"}));
 AddAdjective("brown");
 SetLong(
"A rat with brown fur, about one foot long. "
"It scurries around on the floor.\n"
        );
 SetLevel(3);
 SetInt(1);
 SetDex(18);
 SetGender(GENDER_NEUTER);
 SetAttribute("MagicDefence",10);
 SetAggressive(1);
 SetAttackChance(2);
 SetHands(({ ({"sharp teeth",0,8}), ({"tail",0,3}) }));
}
