// SN:PYAio=a^RX3;mLHg
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m骆驼[2;37;0m", ({"luo tuo"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "一看就知道是一头温顺的骆驼,大家快来骑吧
它是段天德的坐骑。
");
        set_temp("owner_id", "xiaocat");
        set_temp("owner_name", "段天德");
        ::setup();
}

