// SN:AYK<C<3<_Xla:ehV
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m小[1;33m兽兽[2;37;0m", ({"xia_shou shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "小小兽
它是真梦的坐骑。
");
        set_temp("owner_id", "xia");
        set_temp("owner_name", "真梦");
        ::setup();
}

