// SN:X]8Y>WmT>Rbc?L5X
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m石猴猴[2;37;0m", ({"shi hou"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "pker坐骑
它是段杀的坐骑。
");
        set_temp("owner_id", "pker");
        set_temp("owner_name", "段杀");
        ::setup();
}

