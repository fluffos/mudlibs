// SN:R7MClO6VVcXoM_Bn
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("老马[2;37;0m", ({"lao ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "一匹老马
它是心娥的坐骑。
");
        set_temp("owner_id", "emei");
        set_temp("owner_name", "心娥");
        ::setup();
}

