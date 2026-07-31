// SN:=d_?bEB7XoHNJ:Zi
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m单片驹[2;37;0m", ({"danpian ju"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "～～～～～～～～～～～～～～～
它是丹药三号的坐骑。
");
        set_temp("owner_id", "danyaoc");
        set_temp("owner_name", "丹药三号");
        ::setup();
}

