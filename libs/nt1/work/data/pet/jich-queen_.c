// SN:BMQ3n_6P\no=G1hd
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m明兽[2;37;0m", ({"queen_ shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "他是只小怪兽
它是明志的坐骑。
");
        set_temp("owner_id", "jich");
        set_temp("owner_name", "明志");
        ::setup();
}

