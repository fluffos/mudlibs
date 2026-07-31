// SN:WfD1GD06EFbkHIlD
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m血刀狼狼[2;37;0m", ({"jkke lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "你的右手
它是血魔狂龙的坐骑。
");
        set_temp("owner_id", "jkkke");
        set_temp("owner_name", "血魔狂龙");
        ::setup();
}

