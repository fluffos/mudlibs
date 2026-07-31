// SN:6aKMo=K_=h@ZlQPA
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("爱我别走驹[2;37;0m", ({"rideto_dali ju"}));        
        set("gender", "女性");                
        set("unit", "匹");
        set("long", "爱我别走
它是段档的坐骑。
");
        set_temp("owner_id", "save");
        set_temp("owner_name", "段档");
        ::setup();
}

