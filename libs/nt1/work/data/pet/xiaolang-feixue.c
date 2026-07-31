// SN:a5UK428NmnYKTWn6
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("汗血宝马[2;37;0m", ({"feixue ma"}));        
        set("gender", "女性");                
        set("unit", "匹");
        set("long", "和他主人一样永远寂寞
它是永远寂寞的坐骑。
");
        set_temp("owner_id", "xiaolang");
        set_temp("owner_name", "永远寂寞");
        ::setup();
}

