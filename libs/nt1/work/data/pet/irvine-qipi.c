// SN:0gdX>\AGGmB?J7F=
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m七皮狼[2;37;0m", ({"qipi lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "它色色的
它是唐云扬的坐骑。
");
        set_temp("owner_id", "irvine");
        set_temp("owner_name", "唐云扬");
        ::setup();
}

