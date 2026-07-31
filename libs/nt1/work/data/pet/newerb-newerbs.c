// SN:^QDNdOUVH@An8m^e
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[33m老虎啊老虎[2;37;0m", ({"newerbs hu"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "没什么好描述的
它是名字难取的坐骑。
");
        set_temp("owner_id", "newerb");
        set_temp("owner_name", "名字难取");
        ::setup();
}

