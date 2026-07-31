// SN:8=IfCclQV3OX7lLG
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[35m紫遛马[2;37;0m", ({"ziliu ma"}));        
        set("gender", "女性");                
        set("unit", "匹");
        set("long", "mmm.
它是炮手的坐骑。
");
        set_temp("owner_id", "paos");
        set_temp("owner_name", "炮手");
        ::setup();
}

