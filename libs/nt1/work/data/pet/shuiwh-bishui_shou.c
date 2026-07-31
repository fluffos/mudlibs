// SN:3=OlX:dj?EZRlWCi
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;34m碧水晶睛兽[2;37;0m", ({"bishui_shou shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "就是头野兽。
它是水无恨的坐骑。
");
        set_temp("owner_id", "shuiwh");
        set_temp("owner_name", "水无恨");
        ::setup();
}

