// SN:Jh@VC:o@KPb^A<>R
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m银貂[2;37;0m", ({"yin diao"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "$HIW$银
它是段浪的坐骑。
");
        set_temp("owner_id", "smirk");
        set_temp("owner_name", "段浪");
        ::setup();
}

