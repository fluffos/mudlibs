// SN:Ij00YBXWS:abb30m
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;34m天魔狼[2;37;0m", ({"tianmo lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "天魔
它是将臣的坐骑。
");
        set_temp("owner_id", "vampire");
        set_temp("owner_name", "将臣");
        ::setup();
}

