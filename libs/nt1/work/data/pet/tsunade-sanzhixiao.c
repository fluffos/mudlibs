// SN:JUi<:cKmXn@5:WCD
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m三只小熊[2;37;0m", ({"sanzhixiao xiong"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "三只小熊阿.
它是纲手的坐骑。
");
        set_temp("owner_id", "tsunade");
        set_temp("owner_name", "纲手");
        ::setup();
}

