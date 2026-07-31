// SN:JTRZA\K\Z1A_A1VZ
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m剑狼[2;37;0m", ({"wer lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "???
它是剑路的坐骑。
");
        set_temp("owner_id", "werty");
        set_temp("owner_name", "剑路");
        ::setup();
}

