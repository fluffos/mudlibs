// SN:H_f1lbECUonHi_XG
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m野鹤[2;37;0m", ({"yie he"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "$HIR$小野的鹤。
它是张山的坐骑。
");
        set_temp("owner_id", "zsf");
        set_temp("owner_name", "张山");
        ::setup();
}

