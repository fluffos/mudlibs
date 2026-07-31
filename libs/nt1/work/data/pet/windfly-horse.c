// SN:b>meG40WRoRkBD:5
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("宝马[2;37;0m", ({"horse ma"}));        
        set("gender", "女性");                
        set("unit", "匹");
        set("long", "finish
它是风起的坐骑。
");
        set_temp("owner_id", "windfly");
        set_temp("owner_name", "风起");
        ::setup();
}

