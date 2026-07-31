// SN:MLRUR14gL]?PiA?3
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("小马[2;37;0m", ({"xxiao ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "一匹小马
它是米一的坐骑。
");
        set_temp("owner_id", "damia");
        set_temp("owner_name", "米一");
        ::setup();
}

