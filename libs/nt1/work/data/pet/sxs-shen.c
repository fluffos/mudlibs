// SN:O\Y\=V47>kU@8P@;
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("神雕[2;37;0m", ({"shen diao"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "汗血宝雕
它是大山的坐骑。
");
        set_temp("owner_id", "sxs");
        set_temp("owner_name", "大山");
        ::setup();
}

