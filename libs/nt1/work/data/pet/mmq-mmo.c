// SN:MnWA6glQIk8L@C>:
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("大白马[2;37;0m", ({"mmo ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "大白
它是澄龙的坐骑。
");
        set_temp("owner_id", "mmq");
        set_temp("owner_name", "澄龙");
        ::setup();
}

