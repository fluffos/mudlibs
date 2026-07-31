// SN:OHVg=\IaC18b4h`B
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m宝马[2;37;0m", ({"liangchaowei ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "宝马
它是梁朝伟的坐骑。
");
        set_temp("owner_id", "tgb");
        set_temp("owner_name", "梁朝伟");
        ::setup();
}

