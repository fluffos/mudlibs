// SN:UZB;[Y`mReW223oX
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m小明骡[2;37;0m", ({"ming luo"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "arming，变形！！
它是小婷的坐骑。
");
        set_temp("owner_id", "xiaoting");
        set_temp("owner_name", "小婷");
        ::setup();
}

