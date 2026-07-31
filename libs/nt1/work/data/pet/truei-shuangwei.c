// SN:B`GEiR411=RUM=h;
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m双尾驼[2;37;0m", ({"shuangwei tuo"}));        
        set("gender", "女性");                
        set("unit", "头");
        set("long", "雪山 邢双 之坐骑
它是邢双的坐骑。
");
        set_temp("owner_id", "truei");
        set_temp("owner_name", "邢双");
        ::setup();
}

