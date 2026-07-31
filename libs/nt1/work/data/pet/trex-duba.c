// SN:82:D[_c5N]8;[WYW
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m飞天兽[2;37;0m", ({"duba shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "它是一只怪兽
它是独霸的坐骑。
");
        set_temp("owner_id", "trex");
        set_temp("owner_name", "独霸");
        ::setup();
}

