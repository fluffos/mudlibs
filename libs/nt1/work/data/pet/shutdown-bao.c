// SN:K;H<YB>iU6R@]?P:
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m汗血宝马[2;37;0m", ({"bao ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "^_^
它是关机的坐骑。
");
        set_temp("owner_id", "shutdown");
        set_temp("owner_name", "关机");
        ::setup();
}

