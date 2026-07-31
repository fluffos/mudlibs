// SN:dRKP^@5V3<fM3^H8
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("飞天雕[2;37;0m", ({"feilong diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "飞天神吊
它是南郭后生的坐骑。
");
        set_temp("owner_id", "playerb");
        set_temp("owner_name", "南郭后生");
        ::setup();
}

