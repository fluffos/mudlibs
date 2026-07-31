// SN:GoLRBL:P06JKj^[]
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("小雪象[2;37;0m", ({"flybody xiang"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "身如雪白
它是段笑笑的坐骑。
");
        set_temp("owner_id", "cper");
        set_temp("owner_name", "段笑笑");
        ::setup();
}

