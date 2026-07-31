// SN:h7\d:WTeACmSdg\9
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m五彩鹿[2;37;0m", ({"xun_lu lu"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "一代大虾寻寻的飞机，上边有好多ak47,大家小心防范，以防惹火
它是枪下蛋的坐骑。
");
        set_temp("owner_id", "xunxun");
        set_temp("owner_name", "枪下蛋");
        ::setup();
}

