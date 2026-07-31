// SN:a0RD_BMeDcWXVW[5
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[33m招财兽[2;37;0m", ({"zhaocai shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "能找到藏宝的上古异兽
它是农业银行的坐骑。
");
        set_temp("owner_id", "abc");
        set_temp("owner_name", "农业银行");
        ::setup();
}

