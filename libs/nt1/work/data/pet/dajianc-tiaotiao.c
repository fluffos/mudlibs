// SN:Gc\UDSYW@ANJkGf3
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m小跳狼[2;37;0m", ({"tiaotiao lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "好狼一只
它是何济二的坐骑。
");
        set_temp("owner_id", "dajianc");
        set_temp("owner_name", "何济二");
        ::setup();
}

