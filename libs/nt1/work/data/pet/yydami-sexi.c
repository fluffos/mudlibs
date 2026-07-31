// SN:FQ>Y[@6Sj1DOCQ2H
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("云中鹤[2;37;0m", ({"sexi he"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "和尚的鹤
它是澄王的坐骑。
");
        set_temp("owner_id", "yydami");
        set_temp("owner_name", "澄王");
        ::setup();
}

