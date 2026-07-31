// SN:aKhJ=Q]nl^mAiEmF
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m风[1;31m火[1;33m雷[1;34m电兽[2;37;0m", ({"fhld shou"}));        
        set("gender", "女性");                
        set("unit", "头");
        set("long", "他是世界上 守护著四方 的魔兽
它是天剑的坐骑。
");
        set_temp("owner_id", "tianjian");
        set_temp("owner_name", "天剑");
        ::setup();
}

