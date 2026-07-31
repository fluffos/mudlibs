// SN:eR>\VTTT]1g[@DH`
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m宝马[2;37;0m", ({"liudehua ma"}));        
        set("gender", "女性");                
        set("unit", "匹");
        set("long", "宝马喔
它是刘德华的坐骑。
");
        set_temp("owner_id", "qaz");
        set_temp("owner_name", "刘德华");
        ::setup();
}

