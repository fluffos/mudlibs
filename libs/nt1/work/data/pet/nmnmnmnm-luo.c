// SN:Uh?mCH:TnY`o<YWo
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m骆驼[2;37;0m", ({"luo tuo"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "老农的坐骑
它是老农的坐骑。
");
        set_temp("owner_id", "nmnmnmnm");
        set_temp("owner_name", "老农");
        ::setup();
}

