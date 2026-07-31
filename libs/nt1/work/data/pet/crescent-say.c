// SN:[>W8lRBKOWZFEC<\
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[35m紫[1;37m晶[1;31m虎[2;37;0m", ({"say hu"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "say
它是段枫儿的坐骑。
");
        set_temp("owner_id", "crescent");
        set_temp("owner_name", "段枫儿");
        ::setup();
}

