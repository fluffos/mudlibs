// SN:kP@bO_]kV<NLc5bL
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[31m火茏豹[2;37;0m", ({"baopp bao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "PPMO坐骑
它是胡头的坐骑。
");
        set_temp("owner_id", "ppmo");
        set_temp("owner_name", "胡头");
        ::setup();
}

