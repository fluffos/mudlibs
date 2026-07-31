// SN:MF]8oDY8IU1F[HIR
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m一箭双雕[2;37;0m", ({"super diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "它是soho的小雕
它是澄空的坐骑。
");
        set_temp("owner_id", "soho");
        set_temp("owner_name", "澄空");
        ::setup();
}

