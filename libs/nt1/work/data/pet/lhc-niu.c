// SN:1m1Y7S<UG?l@NQ51
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("牛比牛[2;37;0m", ({"niu niu"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "小母牛贴商标。真牛比
它是灵狐宠的坐骑。
");
        set_temp("owner_id", "lhc");
        set_temp("owner_name", "灵狐宠");
        ::setup();
}

