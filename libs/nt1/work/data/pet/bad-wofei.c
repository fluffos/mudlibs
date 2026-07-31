// SN:E?_[nn8EHHHh`]=e
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m我飞鹤[2;37;0m", ({"wofei he"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "文
它是渡男的坐骑。
");
        set_temp("owner_id", "bad");
        set_temp("owner_name", "渡男");
        ::setup();
}

