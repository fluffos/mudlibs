// SN:dL=1YXhmSm6@Pa4H
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m姜二子兽[2;37;0m", ({"erzi shou"}));        
        set("gender", "女性");                
        set("unit", "头");
        set("long", "不想描述
它是乔峰的坐骑。
");
        set_temp("owner_id", "strike");
        set_temp("owner_name", "乔峰");
        ::setup();
}

