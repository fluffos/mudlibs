// SN:FBbYg06eToncIb6^
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("紫马[2;37;0m", ({"ye_ma ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "野马一只
它是唐药的坐骑。
");
        set_temp("owner_id", "tangyao");
        set_temp("owner_name", "唐药");
        ::setup();
}

