// SN:9=4:?b2GL^=XS@j@
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m顽固[1;32m象[2;37;0m", ({"xiao xiang"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "$HIG$老顽固的笨笨坐骑
它是明老的坐骑。
");
        set_temp("owner_id", "lwg");
        set_temp("owner_name", "明老");
        ::setup();
}

