// SN:1QR:\Qb>_1lRgn6;
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("仙鹤鹤[2;37;0m", ({"feihe he"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "这是一只仙鹤
它是桃花二号的坐骑。
");
        set_temp("owner_id", "thwork");
        set_temp("owner_name", "桃花二号");
        ::setup();
}

