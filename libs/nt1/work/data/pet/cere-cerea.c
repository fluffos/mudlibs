// SN:SLiT<l`RX@ENe8bB
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("小马[2;37;0m", ({"cerea ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "只
它是水无珩的坐骑。
");
        set_temp("owner_id", "cere");
        set_temp("owner_name", "水无珩");
        ::setup();
}

