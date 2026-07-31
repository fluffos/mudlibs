// SN:1cNOEhXPne\<R?]G
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("乌龙马[2;37;0m", ({"wulong ma"}));        
        set("gender", "女性");                
        set("unit", "匹");
        set("long", "乌龙
它是唐颖的坐骑。
");
        set_temp("owner_id", "flash");
        set_temp("owner_name", "唐颖");
        ::setup();
}

