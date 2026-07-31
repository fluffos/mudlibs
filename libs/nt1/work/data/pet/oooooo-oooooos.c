// SN:4WAl4hgU[>MV91d0
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[33m老虎[2;37;0m", ({"oooooos hu"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "嘿嘿
它是明明的坐骑。
");
        set_temp("owner_id", "oooooo");
        set_temp("owner_name", "明明");
        ::setup();
}

