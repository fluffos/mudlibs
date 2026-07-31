// SN:>ejZkm1Wi;m37h@a
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m火[1;35m麒麟狮[2;37;0m", ({"xylx shi"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "$HIR$一片火云
它是无笑的坐骑。
");
        set_temp("owner_id", "norain");
        set_temp("owner_name", "无笑");
        ::setup();
}

