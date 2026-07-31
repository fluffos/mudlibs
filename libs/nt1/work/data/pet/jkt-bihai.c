// SN:l297\5?;A<GaASaX
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m碧海云烟[1;31m兽兽[2;37;0m", ({"bihai shou"}));        
        set("gender", "女性");                
        set("unit", "头");
        set("long", "天庭的神兽
它是渡独的坐骑。
");
        set_temp("owner_id", "jkt");
        set_temp("owner_name", "渡独");
        ::setup();
}

