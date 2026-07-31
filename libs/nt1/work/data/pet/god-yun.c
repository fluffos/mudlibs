// SN:Bcb`6RDdX?YE7W[a
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m白鹤[2;37;0m", ({"yun he"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "轻轻的飘来，静静的离去
它是上帝的坐骑。
");
        set_temp("owner_id", "god");
        set_temp("owner_name", "上帝");
        ::setup();
}

