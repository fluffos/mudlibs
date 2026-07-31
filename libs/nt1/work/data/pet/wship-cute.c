// SN:TdhmJg?f0YP@<^P3
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("大笨象[2;37;0m", ({"cute xiang"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "这是猪猪养的大笨象和猪猪一样只会吃东西很可爱的哦
它是溟剑的坐骑。
");
        set_temp("owner_id", "wship");
        set_temp("owner_name", "溟剑");
        ::setup();
}


