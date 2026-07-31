// SN:n\JOS3[G060[C:=V
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m职业[1;33m药[1;37m马[2;37;0m", ({"idanb ma"}));        
        set("gender", "女性");                
        set("unit", "匹");
        set("long", "啊
它是丹二的坐骑。
");
        set_temp("owner_id", "danb");
        set_temp("owner_name", "丹二");
        ::setup();
}

