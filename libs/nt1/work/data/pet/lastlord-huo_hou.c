// SN:nZ@^^j`[cnCZeC[P
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m火猴猴[2;37;0m", ({"huo_hou hou"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "肥肥的猴子
它是摩诃流星的坐骑。
");
        set_temp("owner_id", "lastlord");
        set_temp("owner_name", "摩诃流星");
        ::setup();
}

