// SN:=5;UjU_l;Hk`C7m1
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m丹[1;31m顶[1;31m鹤[2;37;0m", ({"dan he"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "这是一只可爱的丹顶鹤，我最喜欢了。
它是深蓝的坐骑。
");
        set_temp("owner_id", "celeste");
        set_temp("owner_name", "深蓝");
        ::setup();
}

