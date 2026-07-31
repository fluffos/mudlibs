// SN:L8ToALOeiJGRWe]M
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m野牛[2;37;0m", ({"fans niu"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "狂奔
它是哈儿的坐骑。
");
        set_temp("owner_id", "haer");
        set_temp("owner_name", "哈儿");
        ::setup();
}

