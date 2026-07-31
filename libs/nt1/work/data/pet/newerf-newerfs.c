// SN:liMk8LRfhb_S1eWP
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[33m老虎[2;37;0m", ({"newerfs hu"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "老虎都不知道啊
它是丹玉磨的坐骑。
");
        set_temp("owner_id", "newerf");
        set_temp("owner_name", "丹玉磨");
        ::setup();
}

