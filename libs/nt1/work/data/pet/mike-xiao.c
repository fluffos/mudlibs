// SN:1n^h7HFcDNF7leK=
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m小绿鹿[2;37;0m", ({"xiao lu"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "这是小麦棵的美丽的小鹿。
它是麦棵小的坐骑。
");
        set_temp("owner_id", "mike");
        set_temp("owner_name", "麦棵小");
        ::setup();
}

