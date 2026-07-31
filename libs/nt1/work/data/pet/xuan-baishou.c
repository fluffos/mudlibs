// SN:a\C2>\L7e`TNSbE?
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m白首太玄狼[2;37;0m", ({"baishou lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "太玄奥意。　
它是明邪的坐骑。
");
        set_temp("owner_id", "xuan");
        set_temp("owner_name", "明邪");
        ::setup();
}

