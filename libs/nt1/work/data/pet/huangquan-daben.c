// SN:^ikF4AMLc5hHl41R
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m大笨象[2;37;0m", ({"daben xiang"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "$HIW$大笨
它是黄泉的坐骑。
");
        set_temp("owner_id", "huangquan");
        set_temp("owner_name", "黄泉");
        ::setup();
}

