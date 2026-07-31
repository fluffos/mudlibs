// SN:75E3ee97mFB\C`85
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("神雕雕[2;37;0m", ({"diao diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "这是神雕
它是杨泥虫的坐骑。
");
        set_temp("owner_id", "yangnt");
        set_temp("owner_name", "杨泥虫");
        ::setup();
}

