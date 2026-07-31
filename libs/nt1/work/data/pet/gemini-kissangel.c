// SN:Pc?6`\WaoPR=DVR1
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("麒麟兽[2;37;0m", ({"kissangel shou"}));        
        set("gender", "女性");                
        set("unit", "头");
        set("long", "麒麟
它是宫仁俊子的坐骑。
");
        set_temp("owner_id", "gemini");
        set_temp("owner_name", "宫仁俊子");
        ::setup();
}

