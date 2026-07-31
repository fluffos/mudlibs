// SN:U`:oQ_giaj[:8PDm
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m老大兽[2;37;0m", ({"big shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "他是阿大的坐骑
它是阿大的坐骑。
");
        set_temp("owner_id", "ada");
        set_temp("owner_name", "阿大");
        ::setup();
}

