// SN:0M_HeK7X2=;n5DdL
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[37m藏马[34m妖狐[2;37;0m", ({"tongyizhe hu"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "不用想啦，就是幽游白书里的藏马啦
它是苜蓿的坐骑。
");
        set_temp("owner_id", "muxv");
        set_temp("owner_name", "苜蓿");
        ::setup();
}

