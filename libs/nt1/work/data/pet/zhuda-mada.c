// SN:lc2TJQ5QEdiAJBIG
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("天马[2;37;0m", ({"mada ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "马啊！这都不认识？
它是猪极拳的坐骑。
");
        set_temp("owner_id", "zhuda");
        set_temp("owner_name", "猪极拳");
        ::setup();
}

