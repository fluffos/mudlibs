// SN:]M]D_IY30PaeUFoS
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("雕雕[2;37;0m", ({"diao diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "一
它是闲聊的坐骑。
");
        set_temp("owner_id", "klatch");
        set_temp("owner_name", "闲聊");
        ::setup();
}

