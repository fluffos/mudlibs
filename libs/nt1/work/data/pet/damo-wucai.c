// SN:M_?B^[52H@cj;fa;
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m五[1;32m彩[1;33m神[1;36m牛[2;37;0m", ({"wucai niu"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "五彩神妞
它是净达的坐骑。
");
        set_temp("owner_id", "damo");
        set_temp("owner_name", "净达");
        ::setup();
}

