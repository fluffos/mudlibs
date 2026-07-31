// SN:^Q1Bmd<:a<e=9dPm
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("宝马驴[2;37;0m", ({"fans lv"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "跑啊。。。跑啊。。。
它是徐子陵的坐骑。
");
        set_temp("owner_id", "xuziling");
        set_temp("owner_name", "徐子陵");
        ::setup();
}

