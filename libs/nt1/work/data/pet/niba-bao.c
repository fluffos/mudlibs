// SN:c9m;5EAK8:8=QfK5
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m汗血宝马[2;37;0m", ({"bao ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "^_^
它是泥巴的坐骑。
");
        set_temp("owner_id", "niba");
        set_temp("owner_name", "泥巴");
        ::setup();
}

