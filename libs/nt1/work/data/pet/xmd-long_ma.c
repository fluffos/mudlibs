// SN:^DcA4@<<T2IJlE1_
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("小灰马[2;37;0m", ({"long_ma ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "灰灰的
它是唐李的坐骑。
");
        set_temp("owner_id", "xmd");
        set_temp("owner_name", "唐李");
        ::setup();
}

