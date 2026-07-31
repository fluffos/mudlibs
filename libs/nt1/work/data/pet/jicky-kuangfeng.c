// SN:7o?2bmCBN2`cjFgM
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m狂风狼[2;37;0m", ({"kuangfeng lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "hp
它是毛毛的坐骑。
");
        set_temp("owner_id", "jicky");
        set_temp("owner_name", "毛毛");
        ::setup();
}

