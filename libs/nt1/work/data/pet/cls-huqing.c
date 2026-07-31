// SN:ddi_[[A2i=h]cD]K
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m胡[1;37m青牛[2;37;0m", ({"huqing niu"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "这不是药王坐骑嘛？怎么跑到这里来了？？
它是程灵素的坐骑。
");
        set_temp("owner_id", "cls");
        set_temp("owner_name", "程灵素");
        ::setup();
}

