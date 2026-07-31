// SN:2cO9_?1SCd4k_3V5
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m汗血宝马[2;37;0m", ({"bao ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "^_^
它是妙柔的坐骑。
");
        set_temp("owner_id", "tangrou");
        set_temp("owner_name", "妙柔");
        ::setup();
}

