// SN:GA5b_`UTedE_lL4T
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m小胖象[2;37;0m", ({"xiaopang xiang"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "一只象
它是火火的坐骑。
");
        set_temp("owner_id", "zen");
        set_temp("owner_name", "火火");
        ::setup();
}

