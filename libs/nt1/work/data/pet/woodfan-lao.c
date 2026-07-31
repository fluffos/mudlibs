// SN:EB0k>^hQMV0l6mYH
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m老牛[2;37;0m", ({"lao niu"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "一只老牛
它是木头贩子的坐骑。
");
        set_temp("owner_id", "woodfan");
        set_temp("owner_name", "木头贩子");
        ::setup();
}

