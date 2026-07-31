// SN:C`=IlJbj4[Ze1GKV
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;35m鸟鹤[2;37;0m", ({"qiangqiang he"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "$HIM$鸟
它是夏天的坐骑。
");
        set_temp("owner_id", "qiang");
        set_temp("owner_name", "夏天");
        ::setup();
}

