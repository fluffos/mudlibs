// SN:_KYS\B\YF=o7nIOX
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m炎魔豹[2;37;0m", ({"darkness bao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "小家伙
它是慕容翎的坐骑。
");
        set_temp("owner_id", "lingling");
        set_temp("owner_name", "慕容翎");
        ::setup();
}

