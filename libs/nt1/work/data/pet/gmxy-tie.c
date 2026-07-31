// SN:V<l:A8^C@WDH@I\M
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[37m铁狼[2;37;0m", ({"tie lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "它是我的坐骑。
它是消魂的坐骑。
");
        set_temp("owner_id", "gmxy");
        set_temp("owner_name", "消魂");
        ::setup();
}

