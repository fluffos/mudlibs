// SN:i]iJKk;6TbFn75O[
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m色狼[2;37;0m", ({"sex lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "$HIR$一条色狼
它是红叶的坐骑。
");
        set_temp("owner_id", "chong");
        set_temp("owner_name", "红叶");
        ::setup();
}

