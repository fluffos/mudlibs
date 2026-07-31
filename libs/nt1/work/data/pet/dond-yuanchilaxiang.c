// SN:eLR0YZTG3RaGHi0Z
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("蜡象象[2;37;0m", ({"yuanchilaxiang xiang"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "这就是呆老四的坐骑
它是呆老四的坐骑。
");
        set_temp("owner_id", "dond");
        set_temp("owner_name", "呆老四");
        ::setup();
}

