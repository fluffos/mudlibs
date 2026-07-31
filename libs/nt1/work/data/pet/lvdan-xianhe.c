// SN:L@4MA=K`hio:cJST
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;34m仙[1;34m鹤鹤[2;37;0m", ({"xianhe he"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "$HIB$仙$HIB$鹤
它是上官丹丹的坐骑。
");
        set_temp("owner_id", "lvdan");
        set_temp("owner_name", "上官丹丹");
        ::setup();
}

