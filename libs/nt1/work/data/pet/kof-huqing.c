// SN:>A1BB80oHn^T?JZ<
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m胡青牛[2;37;0m", ({"huqing niu"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "$HIY$一只会治百病的神牛哦！
它是段不了的坐骑。
");
        set_temp("owner_id", "kof");
        set_temp("owner_name", "段不了");
        ::setup();
}

