// SN:Hf31`4`c\<UC?S>P
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m职业[1;33m药[1;37m马[2;37;0m", ({"idanh ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "啊
它是丹八的坐骑。
");
        set_temp("owner_id", "danh");
        set_temp("owner_name", "丹八");
        ::setup();
}

