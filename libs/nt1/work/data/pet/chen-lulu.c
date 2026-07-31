// SN:Uk?l_Q`bSS4DCiPa
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;35m碧灵鹿[2;37;0m", ({"lulu lu"}));        
        set("gender", "女性");                
        set("unit", "头");
        set("long", "$HIG$明天会更好
它是孙二娘的坐骑。
");
        set_temp("owner_id", "chen");
        set_temp("owner_name", "孙二娘");
        ::setup();
}

