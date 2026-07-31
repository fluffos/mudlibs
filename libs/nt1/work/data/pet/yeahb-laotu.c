// SN:<;NQa@ZBeg5\L>V]
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("老秃驴[2;37;0m", ({"laotu lv"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "少林寺掌门
它是十龙的坐骑。
");
        set_temp("owner_id", "yeahb");
        set_temp("owner_name", "十龙");
        ::setup();
}

