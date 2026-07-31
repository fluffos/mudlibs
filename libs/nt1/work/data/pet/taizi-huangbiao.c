// SN:YI_Qf8J9R74O29Za
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m黄膘马[2;37;0m", ({"huangbiao ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "赤兔马ㄉ弟弟
它是太子的坐骑。
");
        set_temp("owner_id", "taizi");
        set_temp("owner_name", "太子");
        ::setup();
}

