// SN:1HTZmeTY[2j]FcSL
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m困成马[2;37;0m", ({"sleep_ ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "一头只知道睡觉的马。
它是杂学的坐骑。
");
        set_temp("owner_id", "zanxue");
        set_temp("owner_name", "杂学");
        ::setup();
}

