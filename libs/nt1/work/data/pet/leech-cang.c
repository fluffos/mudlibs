// SN:T7??j8M8:@@>F8?d
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[35m绝地苍狼狼[2;37;0m", ({"cang lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "它很乖
它是慕容绝爱的坐骑。
");
        set_temp("owner_id", "leech");
        set_temp("owner_name", "慕容绝爱");
        ::setup();
}

