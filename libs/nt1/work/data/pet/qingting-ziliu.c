// SN:VQO;nh9WVli0@0>`
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[35m紫遛马[2;37;0m", ({"ziliu ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "$MAG$紫遛
它是蜻蜓的坐骑。
");
        set_temp("owner_id", "qingting");
        set_temp("owner_name", "蜻蜓");
        ::setup();
}

