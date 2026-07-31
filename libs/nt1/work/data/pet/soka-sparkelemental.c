// SN:BFFoNcI?2=WBm>jN
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m血狼[2;37;0m", ({"sparkelemental lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "嗜血如命
它是段小凡的坐骑。
");
        set_temp("owner_id", "soka");
        set_temp("owner_name", "段小凡");
        ::setup();
}

