// SN:@ko5]io=@59C8`8L
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m时光驹[2;37;0m", ({"shiguang ju"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "'@@
它是前世今生的坐骑。
");
        set_temp("owner_id", "samsara");
        set_temp("owner_name", "前世今生");
        ::setup();
}

