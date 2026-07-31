// SN:;b6FhE4c5BWT=W29
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m乘风鹤鹤[2;37;0m", ({"snail he"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "一只小白鹤～！
它是慕容逸风的坐骑。
");
        set_temp("owner_id", "yifeng");
        set_temp("owner_name", "慕容逸风");
        ::setup();
}

