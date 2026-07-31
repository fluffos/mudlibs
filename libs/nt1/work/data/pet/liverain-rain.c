// SN:dm>G_i`>PO>ShmCF
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;35m风云兽[2;37;0m", ({"rain shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "$HIM$风云
它是无天无道的坐骑。
");
        set_temp("owner_id", "liverain");
        set_temp("owner_name", "无天无道");
        ::setup();
}

