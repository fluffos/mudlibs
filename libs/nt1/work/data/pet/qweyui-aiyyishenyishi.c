// SN:>8WRcn]^:Wf84fl<
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("龙啸九天雕[2;37;0m", ({"aiyyishenyishi diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "他是我和莹的宠物.
它是古墓星辰的坐骑。
");
        set_temp("owner_id", "qweyui");
        set_temp("owner_name", "古墓星辰");
        ::setup();
}

