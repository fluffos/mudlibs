// SN:iB@3_nUS<URkh_3H
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m威武狮[2;37;0m", ({"weiwu shi"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "tan的坐骑
它是柳十七的坐骑。
");
        set_temp("owner_id", "tan");
        set_temp("owner_name", "柳十七");
        ::setup();
}

