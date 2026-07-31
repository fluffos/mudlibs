// SN:4QNDOECMWE^]dPNR
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m开明兽[2;37;0m", ({"kaiming shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "桃花岛 乐桐 之坐骑
它是乐桐的坐骑。
");
        set_temp("owner_id", "truee");
        set_temp("owner_name", "乐桐");
        ::setup();
}

