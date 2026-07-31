// SN:Qe;6fXHmdk2^Hn@0
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m赤[1;33m兔马[2;37;0m", ({"chitu ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "我的坐骑
它是风月无边的坐骑。
");
        set_temp("owner_id", "kenie");
        set_temp("owner_name", "风月无边");
        ::setup();
}

