// SN:^Ib@;3Vo56;j1L[h
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("老虎就是虎[2;37;0m", ({"neweras hu"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "老虎有什么好描述的
它是天下的坐骑。
");
        set_temp("owner_id", "newera");
        set_temp("owner_name", "天下");
        ::setup();
}

