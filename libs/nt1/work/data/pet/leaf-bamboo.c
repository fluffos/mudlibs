// SN:afeCQD9;RQZ>QUOg
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m竹马[2;37;0m", ({"bamboo ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "郎骑竹马来
它是樱叶的坐骑。
");
        set_temp("owner_id", "leaf");
        set_temp("owner_name", "樱叶");
        ::setup();
}

