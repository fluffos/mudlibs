// SN:H:4COBWhX:Mm59KH
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m小小马[2;37;0m", ({"ankk ma"}));        
        set("gender", "女性");                
        set("unit", "匹");
        set("long", "123
它是段凰的坐骑。
");
        set_temp("owner_id", "ank");
        set_temp("owner_name", "段凰");
        ::setup();
}

