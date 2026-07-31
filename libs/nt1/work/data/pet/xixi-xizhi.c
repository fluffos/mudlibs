// SN:[RIbCN@OD9OEBM`2
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("喜之狼[2;37;0m", ({"xizhi lang"}));        
        set("gender", "女性");                
        set("unit", "条");
        set("long", "这是xixi的坐骑
它是嘻嘻的坐骑。
");
        set_temp("owner_id", "xixi");
        set_temp("owner_name", "嘻嘻");
        ::setup();
}

