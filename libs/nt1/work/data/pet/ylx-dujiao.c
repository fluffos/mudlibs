// SN:VP_O6d`Oe`1ZdOEO
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m独角兽[2;37;0m", ({"dujiao shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "美女与野兽－独角兽
它是夜来香的坐骑。
");
        set_temp("owner_id", "ylx");
        set_temp("owner_name", "夜来香");
        ::setup();
}

