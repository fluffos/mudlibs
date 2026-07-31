// SN:;46C`Q@1d=o`Se_Q
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("小马[2;37;0m", ({"xxiao ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "一匹小马
它是米三的坐骑。
");
        set_temp("owner_id", "damic");
        set_temp("owner_name", "米三");
        ::setup();
}

