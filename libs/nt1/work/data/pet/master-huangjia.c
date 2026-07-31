// SN:TOMhh\XOH?5dN0W@
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m黄家驹[2;37;0m", ({"huangjia ju"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "……
它是殷正廉的坐骑。
");
        set_temp("owner_id", "master");
        set_temp("owner_name", "殷正廉");
        ::setup();
}

