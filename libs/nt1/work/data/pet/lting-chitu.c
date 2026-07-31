// SN:eTD=;277QH]QW:Bk
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m赤兔马[2;37;0m", ({"chitu ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "它毛色血一般红，真是一匹好马。
它是恋婷的坐骑。
");
        set_temp("owner_id", "lting");
        set_temp("owner_name", "恋婷");
        ::setup();
}

