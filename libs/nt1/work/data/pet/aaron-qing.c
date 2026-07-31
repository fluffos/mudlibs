// SN:RkCN2@IW1E2X4;0P
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("青牛[2;37;0m", ({"qing niu"}));        
        set("gender", "女性");                
        set("unit", "头");
        set("long", "$HIR$你的眼前一黑，接著什么也不知道了....
它是一灯的坐骑。
");
        set_temp("owner_id", "aaron");
        set_temp("owner_name", "一灯");
        ::setup();
}

