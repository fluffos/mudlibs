// SN:aAQZ_VO:jhfHG[KX
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m碧云兽[2;37;0m", ({"biyun shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "通体晶碧,飘逸如云
它是邢全的坐骑。
");
        set_temp("owner_id", "truej");
        set_temp("owner_name", "邢全");
        ::setup();
}

