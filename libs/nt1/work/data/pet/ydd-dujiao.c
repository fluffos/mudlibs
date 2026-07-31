// SN:YI4<4`ekF;8fAa>D
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m独角兽[2;37;0m", ({"dujiao shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "银白色的皮毛，水晶一样细长的角嵌在精灵的额头上。
它是叶多多的坐骑。
");
        set_temp("owner_id", "ydd");
        set_temp("owner_name", "叶多多");
        ::setup();
}

