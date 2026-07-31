// SN:23ig`F\L1E0Wb=`Q
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("紫马[2;37;0m", ({"yema ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "一匹野马
它是唐药的坐骑。
");
        set_temp("owner_id", "tangyao");
        set_temp("owner_name", "唐药");
        ::setup();
}

