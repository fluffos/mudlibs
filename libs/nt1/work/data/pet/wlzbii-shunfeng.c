// SN:^bDP9d5N06c?_fVQ
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[35m顺[1;31m风[1;34m马马[2;37;0m", ({"shunfeng ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "比风还快的马
它是武林争雄的坐骑。
");
        set_temp("owner_id", "wlzbii");
        set_temp("owner_name", "武林争雄");
        ::setup();
}

