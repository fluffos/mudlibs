// SN:JbhN=oPb^[oDl1gL
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("小马[2;37;0m", ({"xxiao ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "一匹小马
它是米四的坐骑。
");
        set_temp("owner_id", "damid");
        set_temp("owner_name", "米四");
        ::setup();
}

