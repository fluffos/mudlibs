// SN:?f47ok`Q;KRg;jb>
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m单峰驼[2;37;0m", ({"danfeng tuo"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "来自西域的一匹单峰驼。
它是唐四藏的坐骑。
");
        set_temp("owner_id", "tang");
        set_temp("owner_name", "唐四藏");
        ::setup();
}

