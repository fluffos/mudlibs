// SN:G1UZB`bNbCR`gJoP
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("羽翼鹤[2;37;0m", ({"yuyi he"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "云中飞舞
它是雪梨的坐骑。
");
        set_temp("owner_id", "xueli");
        set_temp("owner_name", "雪梨");
        ::setup();
}

