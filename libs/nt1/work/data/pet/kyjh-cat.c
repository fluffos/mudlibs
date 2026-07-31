// SN:Gc@ak^[PU<6IPGbN
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("猫猫猫雕[2;37;0m", ({"cat diao"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "埃迪多肯那
它是虚快的坐骑。
");
        set_temp("owner_id", "kyjh");
        set_temp("owner_name", "虚快");
        ::setup();
}

