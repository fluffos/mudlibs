// SN:Kfm:4[CYk2aDemJJ
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("紫霞貂貂[2;37;0m", ({"zxgz diao"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "没什么可以说了，反正很牛
它是清咒的坐骑。
");
        set_temp("owner_id", "zbt");
        set_temp("owner_name", "清咒");
        ::setup();
}

