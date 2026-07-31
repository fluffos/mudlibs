// SN:D[B@=eL12Am7_k3W
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m龙兽[2;37;0m", ({"golds shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "這是隻傳說中神獸
它是海殇君的坐骑。
");
        set_temp("owner_id", "ack");
        set_temp("owner_name", "海殇君");
        ::setup();
}

