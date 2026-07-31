// SN:@cTSaaUDefFc`7VQ
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("皮皮雕[2;37;0m", ({"ppll diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "猪头
它是蚂蚁的坐骑。
");
        set_temp("owner_id", "satyr");
        set_temp("owner_name", "蚂蚁");
        ::setup();
}

