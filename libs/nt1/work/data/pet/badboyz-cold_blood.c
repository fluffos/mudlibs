// SN:PcHL2=o=X;?OiB_a
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m冷血之雕[2;37;0m", ({"cold_blood diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "剑痴的宠物。
它是剑痴的坐骑。
");
        set_temp("owner_id", "badboyz");
        set_temp("owner_name", "剑痴");
        ::setup();
}

