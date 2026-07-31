// SN:HfIk25=bFePGUK9N
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m五[1;31m花马[2;37;0m", ({"hua ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "$HIW$五$HIR$花
它是慕容修的坐骑。
");
        set_temp("owner_id", "murongxiu");
        set_temp("owner_name", "慕容修");
        ::setup();
}

