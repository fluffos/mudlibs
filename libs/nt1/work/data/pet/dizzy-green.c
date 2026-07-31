// SN:i7:9EiROIJ6@QT^H
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m丛林大象[2;37;0m", ({"green xiang"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "$HIR$丛林大
它是唐夜的坐骑。
");
        set_temp("owner_id", "dizzy");
        set_temp("owner_name", "唐夜");
        ::setup();
}

