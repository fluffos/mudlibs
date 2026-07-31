// SN:5hAknA:hJJb@I2[W
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m疯狂驼[2;37;0m", ({"fengkuang tuo"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "别问我是谁
它是欧阳明白的坐骑。
");
        set_temp("owner_id", "again");
        set_temp("owner_name", "欧阳明白");
        ::setup();
}

