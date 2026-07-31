// SN:PMH:Bo]ILOkY<EWP
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m南山虎[2;37;0m", ({"nanshan hu"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "坐骑
它是超级艾迪的坐骑。
");
        set_temp("owner_id", "mainid");
        set_temp("owner_name", "超级艾迪");
        ::setup();
}

