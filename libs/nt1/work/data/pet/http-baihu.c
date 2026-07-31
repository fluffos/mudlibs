// SN:[BCJ\H;K6HN6Na[2
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("白虎驴[2;37;0m", ({"baihu lv"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "白虎
它是中文名字的坐骑。
");
        set_temp("owner_id", "http");
        set_temp("owner_name", "中文名字");
        ::setup();
}

