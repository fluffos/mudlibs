// SN:=:OVO[MV@?7U>;N9
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[35m紫遛马[2;37;0m", ({"ziliu ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "$MAG$紫遛
它是青青的坐骑。
");
        set_temp("owner_id", "qingqing");
        set_temp("owner_name", "青青");
        ::setup();
}

