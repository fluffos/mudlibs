// SN:8WUV\bC]d\hgGYe5
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("小青驼[2;37;0m", ({"baisuzhen tuo"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "一条蛇，是白素贞的丫鬟，法力无边！
它是雨过汀芳的坐骑。
");
        set_temp("owner_id", "koy");
        set_temp("owner_name", "雨过汀芳");
        ::setup();
}

