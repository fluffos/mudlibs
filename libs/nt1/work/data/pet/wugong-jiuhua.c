// SN:Z[d9DW0kT<1lZ\kd
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("九花鹿[2;37;0m", ({"jiuhua lu"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "九花
它是武功的坐骑。
");
        set_temp("owner_id", "wugong");
        set_temp("owner_name", "武功");
        ::setup();
}

