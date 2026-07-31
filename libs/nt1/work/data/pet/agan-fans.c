// SN:M1[@a:TekC<igdfm
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("天狼雕[2;37;0m", ({"fans diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "飞来了。。。。。
它是净纵的坐骑。
");
        set_temp("owner_id", "agan");
        set_temp("owner_name", "净纵");
        ::setup();
}

