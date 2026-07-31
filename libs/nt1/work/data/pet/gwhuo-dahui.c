// SN:kP=Nf^2X?m2Jdi6c
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m大灰狼[2;37;0m", ({"dahui lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "$HIY$大灰
它是鬼舞火的坐骑。
");
        set_temp("owner_id", "gwhuo");
        set_temp("owner_name", "鬼舞火");
        ::setup();
}

