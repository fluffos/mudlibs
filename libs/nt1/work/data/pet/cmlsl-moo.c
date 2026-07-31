// SN:D;5VPLlBeUnCd`=O
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("魔兽[2;37;0m", ({"moo shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "魔与兽，哈哈。。
它是澄湘的坐骑。
");
        set_temp("owner_id", "cmlsl");
        set_temp("owner_name", "澄湘");
        ::setup();
}

