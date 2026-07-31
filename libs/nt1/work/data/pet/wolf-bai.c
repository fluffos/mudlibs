// SN:1O^YQIOK=a:[SF2O
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m白狼[2;37;0m", ({"bai lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "～～～～
它是白狼的坐骑。
");
        set_temp("owner_id", "wolf");
        set_temp("owner_name", "白狼");
        ::setup();
}

