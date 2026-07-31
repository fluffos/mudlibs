// SN:oYW4nK\g?:AfBGc:
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("翻天兽[2;37;0m", ({"fantian shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "悟空大闹天宫时的坐骑。
它是悟空的坐骑。
");
        set_temp("owner_id", "www");
        set_temp("owner_name", "悟空");
        ::setup();
}

