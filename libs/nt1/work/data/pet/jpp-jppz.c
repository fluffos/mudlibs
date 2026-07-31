// SN:>j;9i_fkaMPUD7]N
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("傻雕[2;37;0m", ({"jppz diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "这是jpp的坐骑
它是慕容蛋的坐骑。
");
        set_temp("owner_id", "jpp");
        set_temp("owner_name", "慕容蛋");
        ::setup();
}

