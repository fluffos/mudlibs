// SN:\\=IW@eOC:8VZo<3
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m飞天[1;37m雪驼[2;37;0m", ({"fei tuo"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "一只
它是武当人氏的坐骑。
");
        set_temp("owner_id", "txwd");
        set_temp("owner_name", "武当人氏");
        ::setup();
}

