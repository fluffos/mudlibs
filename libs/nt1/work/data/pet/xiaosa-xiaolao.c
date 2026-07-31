// SN:[;NfNROjLl2Bn^C3
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[35m小老虎[2;37;0m", ({"xiaolao hu"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "最好别看，小心你被我药！
它是小撒的坐骑。
");
        set_temp("owner_id", "xiaosa");
        set_temp("owner_name", "小撒");
        ::setup();
}


