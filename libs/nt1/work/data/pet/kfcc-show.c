// SN:\m^K;U9FH69cRjo=
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[32m雪[32m狼[2;37;0m", ({"show lang"}));        
        set("gender", "女性");                
        set("unit", "条");
        set("long", "$HIW$雪山之狼
它是肯德氏的坐骑。
");
        set_temp("owner_id", "kfcc");
        set_temp("owner_name", "肯德氏");
        ::setup();
}

