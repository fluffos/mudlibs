// SN:[:P@ieU2c=9nH=RN
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m汗血宝马[2;37;0m", ({"bao ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "^_^
它是明明明明的坐骑。
");
        set_temp("owner_id", "newerl");
        set_temp("owner_name", "明明明明");
        ::setup();
}

