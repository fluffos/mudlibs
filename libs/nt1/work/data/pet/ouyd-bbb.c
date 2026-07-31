// SN:gSj6c<HObkSeki0F
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m白驼[2;37;0m", ({"bbb tuo"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "白驼山特产之异兽。
它是欧阳毒的坐骑。
");
        set_temp("owner_id", "ouyd");
        set_temp("owner_name", "欧阳毒");
        ::setup();
}

