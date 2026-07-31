// SN:5SIF<]Q5OYBa9b<a
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m小狮子狮[2;37;0m", ({"xiao_shi shi"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "没什么大不了的
它是慕容夏的坐骑。
");
        set_temp("owner_id", "starg");
        set_temp("owner_name", "慕容夏");
        ::setup();
}

