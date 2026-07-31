// SN:2Z5eh832KanlVYYO
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("太小雕[2;37;0m", ({"hhh diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "太小
它是太二的坐骑。
");
        set_temp("owner_id", "txub");
        set_temp("owner_name", "太二");
        ::setup();
}

