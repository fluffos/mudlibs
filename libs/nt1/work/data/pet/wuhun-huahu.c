// SN:1\<>l?X64lWKXPCG
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m花[1;32m狐雕[2;37;0m", ({"huahu diao"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "速度超级快，不象是坐骑，到象是只可爱的小宠物。
它是无魂的坐骑。
");
        set_temp("owner_id", "wuhun");
        set_temp("owner_name", "无魂");
        ::setup();
}

