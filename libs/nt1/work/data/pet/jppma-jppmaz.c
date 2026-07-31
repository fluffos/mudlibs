// SN:eo[=<8Q4m]c3G>Wl
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("药雕[2;37;0m", ({"jppmaz diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "这是jppma的坐骑
它是傻蛋药一的坐骑。
");
        set_temp("owner_id", "jppma");
        set_temp("owner_name", "傻蛋药一");
        ::setup();
}

