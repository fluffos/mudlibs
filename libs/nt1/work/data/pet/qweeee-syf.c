// SN:fNDXd9nl47CP@46o
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m六耳[1;31m弥[30m猴[2;37;0m", ({"syf hou"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "$HIR$一看就知道是个厉害玩意。
它是舞月的坐骑。
");
        set_temp("owner_id", "qweeee");
        set_temp("owner_name", "舞月");
        ::setup();
}

