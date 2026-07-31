// SN:KJL0H5L>7G\bZAlo
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m大叫驴[2;37;0m", ({"dajiao lv"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "finish
它是龙门客栈的坐骑。
");
        set_temp("owner_id", "kezhanb");
        set_temp("owner_name", "龙门客栈");
        ::setup();
}

