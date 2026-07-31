// SN:hW;fZ:S=en3[]>Yl
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m唐老牛[2;37;0m", ({"tanglao niu"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "啊哈哈哈哈哈
它是唐老鸦的坐骑。
");
        set_temp("owner_id", "duck");
        set_temp("owner_name", "唐老鸦");
        ::setup();
}

