// SN:j?0k0DaRaEOn=H=Z
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("会飞驼[2;37;0m", ({"flying tuo"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "会飞
它是芒果芒果的坐骑。
");
        set_temp("owner_id", "mango");
        set_temp("owner_name", "芒果芒果");
        ::setup();
}

