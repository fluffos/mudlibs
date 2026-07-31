// SN:NET2f^S]emk_WbM=
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m阿毛狮[2;37;0m", ({"a_mao shi"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "这是武神的小坐骑--阿毛，好象没怎么长大唉~
它是武神的坐骑。
");
        set_temp("owner_id", "wushen");
        set_temp("owner_name", "武神");
        ::setup();
}

