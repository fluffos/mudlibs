// SN:1<@lX64Gf4f219SQ
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m火雷狮[2;37;0m", ({"huol shi"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "是只由火神和雷神赴在身的一只猛火雷狮
它是雷斯魔的坐骑。
");
        set_temp("owner_id", "lsm");
        set_temp("owner_name", "雷斯魔");
        ::setup();
}

