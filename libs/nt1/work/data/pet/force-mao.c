// SN:HL2BETfB\DI>KcM?
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m毛[1;33m驹[2;37;0m", ({"mao ju"}));        
        set("gender", "女性");                
        set("unit", "匹");
        set("long", "毛驹
它是内功的坐骑。
");
        set_temp("owner_id", "force");
        set_temp("owner_name", "内功");
        ::setup();
}

