// SN:k^h:2D8k]:XZLW8@
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("白马[2;37;0m", ({"zyun ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "一匹白马
它是紫芸的坐骑。
");
        set_temp("owner_id", "ziyun");
        set_temp("owner_name", "紫芸");
        ::setup();
}

