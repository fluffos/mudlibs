// SN:mYb]f2XGk?KEd_oa
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[35m张果老倒骑驴[2;37;0m", ({"mao lv"}));        
        set("gender", "女性");                
        set("unit", "头");
        set("long", "张果老倒骑毛驴
它是不死魔尊的坐骑。
");
        set_temp("owner_id", "busimozun");
        set_temp("owner_name", "不死魔尊");
        ::setup();
}

