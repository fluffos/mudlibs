// SN:]cSiSV_Q=ilKh1[R
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m血狼狼[2;37;0m", ({"xuelang lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "七匹狼
它是血刀无敌的坐骑。
");
        set_temp("owner_id", "xuexue");
        set_temp("owner_name", "血刀无敌");
        ::setup();
}

