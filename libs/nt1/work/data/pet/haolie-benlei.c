// SN:[bZKNgbml]`UHoIH
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m奔[1;31m雷[1;34m马[2;37;0m", ({"benlei ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "银鞍照白马,疯沓如流星.
它是段星的坐骑。
");
        set_temp("owner_id", "haolie");
        set_temp("owner_name", "段星");
        ::setup();
}

