// SN:1YeKBC^?gNVY_7WY
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[31m血狼[2;37;0m", ({"xue lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "以血饲狼
它是酷头裤头的坐骑。
");
        set_temp("owner_id", "kutou");
        set_temp("owner_name", "酷头裤头");
        ::setup();
}

