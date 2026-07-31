// SN:;eN2bn?QKVfNK[gU
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m小红马[2;37;0m", ({"xiaohong ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "我的....马马
它是胡乱搞的坐骑。
");
        set_temp("owner_id", "dvd");
        set_temp("owner_name", "胡乱搞");
        ::setup();
}

