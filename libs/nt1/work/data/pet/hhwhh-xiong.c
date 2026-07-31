// SN:\`KR9AiKe84N=O@n
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m雄狮[2;37;0m", ({"xiong shi"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "一头雄狮
它是鹰飞筱筱的坐骑。
");
        set_temp("owner_id", "hhwhh");
        set_temp("owner_name", "鹰飞筱筱");
        ::setup();
}

