// SN:21f68n?FLLXD:8IA
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m黄定宇[1;33m教兽[2;37;0m", ({"hjs shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "取保候审赋闲在家
它是段银行的坐骑。
");
        set_temp("owner_id", "olbank");
        set_temp("owner_name", "段银行");
        ::setup();
}

