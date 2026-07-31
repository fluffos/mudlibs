// SN:E]M6i7`nkZ7W^>G5
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m外[1;33m国[1;36m杂种马[2;37;0m", ({"foreign ma"}));        
        set("gender", "女性");                
        set("unit", "匹");
        set("long", "这是一头外国的杂交产生的马.
它是弗兰克林的坐骑。
");
        set_temp("owner_id", "franklin");
        set_temp("owner_name", "弗兰克林");
        ::setup();
}

