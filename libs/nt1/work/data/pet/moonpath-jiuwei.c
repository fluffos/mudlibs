// SN:MHP>f2efSOD775Kf
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m九[1;32m尾[1;31m狐[2;37;0m", ({"jiuwei hu"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "只
它是水货的坐骑。
");
        set_temp("owner_id", "moonpath");
        set_temp("owner_name", "水货");
        ::setup();
}

