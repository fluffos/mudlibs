// SN:IU6Qf1oA?3RH<dN3
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("大笨虎[2;37;0m", ({"audit hu"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "笨头笨脑
它是性不性的坐骑。
");
        set_temp("owner_id", "czauditb");
        set_temp("owner_name", "性不性");
        ::setup();
}

