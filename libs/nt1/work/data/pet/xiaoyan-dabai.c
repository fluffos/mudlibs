// SN:m=9S;=CdiH05ZHmg
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m白鹤[2;37;0m", ({"dabai he"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "全身的羽毛都是白的。
它是段小燕的坐骑。
");
        set_temp("owner_id", "xiaoyan");
        set_temp("owner_name", "段小燕");
        ::setup();
}

