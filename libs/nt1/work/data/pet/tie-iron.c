// SN:5Dm^TP7;hXK9CoVg
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("铁牛牛[2;37;0m", ({"iron niu"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "这就是传说中的那只铁牛。
它是铁手的坐骑。
");
        set_temp("owner_id", "tie");
        set_temp("owner_name", "铁手");
        ::setup();
}

