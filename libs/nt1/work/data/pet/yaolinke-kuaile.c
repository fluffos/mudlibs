// SN:ZdlJ1;9MJa6U9TT\
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m快乐毛[1;33m驴[2;37;0m", ({"kuaile lv"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "我很开心，很快乐。
它是萧峰的坐骑。
");
        set_temp("owner_id", "yaolinke");
        set_temp("owner_name", "萧峰");
        ::setup();
}

