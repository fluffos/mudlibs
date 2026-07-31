// SN:VoZ@4;AkD[LF\GdC
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("宝马[2;37;0m", ({"bao ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "风流女人之马
它是风流女人的坐骑。
");
        set_temp("owner_id", "bow");
        set_temp("owner_name", "风流女人");
        ::setup();
}

