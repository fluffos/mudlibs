// SN:8LWEBYSI8RBK7L_K
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m飞马[2;37;0m", ({"feiiii ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "sucks
它是侠客行的坐骑。
");
        set_temp("owner_id", "xkx");
        set_temp("owner_name", "侠客行");
        ::setup();
}

