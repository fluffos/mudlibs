// SN:_T[JTN@J>7?5HlU6
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[31m绝影马[2;37;0m", ({"jueying ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "$RED$这是一匹全身暗红的千里马，名叫『绝影』。
它是啊穆的坐骑。
");
        set_temp("owner_id", "amu");
        set_temp("owner_name", "啊穆");
        ::setup();
}

