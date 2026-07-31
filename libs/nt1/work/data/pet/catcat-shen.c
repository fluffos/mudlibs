// SN:6liK9c0RLL=e=lC@
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("小白雕[2;37;0m", ({"shen diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "小雪的坐骑
它是段吟雪的坐骑。
");
        set_temp("owner_id", "catcat");
        set_temp("owner_name", "段吟雪");
        ::setup();
}

