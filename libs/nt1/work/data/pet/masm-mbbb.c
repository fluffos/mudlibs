// SN:Pco8bV[cm2`<;\Di
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("比比兽[2;37;0m", ({"mbbb shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "比比兽
它是小光的坐骑。
");
        set_temp("owner_id", "masm");
        set_temp("owner_name", "小光");
        ::setup();
}

