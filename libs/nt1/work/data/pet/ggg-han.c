// SN:?bAR7LgDXfe`EV1M
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("憨憨马[2;37;0m", ({"han ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "憨憨的马
它是澄乖的坐骑。
");
        set_temp("owner_id", "ggg");
        set_temp("owner_name", "澄乖");
        ::setup();
}

