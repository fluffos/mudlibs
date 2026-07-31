// SN:Zi;LSnAo;P406cDC
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m烤全[1;32m羊[2;37;0m", ({"shaokai yang"}));        
        set("gender", "女性");                
        set("unit", "头");
        set("long", "一只烤了了的乳羊.
它是韩明远的坐骑。
");
        set_temp("owner_id", "cry");
        set_temp("owner_name", "韩明远");
        ::setup();
}

