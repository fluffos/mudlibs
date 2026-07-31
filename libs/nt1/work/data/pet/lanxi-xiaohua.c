// SN:_boTEZkbfKYG`15m
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;35m小花鹿[2;37;0m", ({"xiaohua lu"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "$HIM$一只可爱的小花鹿
它是兰惜儿的坐骑。
");
        set_temp("owner_id", "lanxi");
        set_temp("owner_name", "兰惜儿");
        ::setup();
}

