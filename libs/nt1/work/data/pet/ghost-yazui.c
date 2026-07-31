// SN:4=fRl_c>;glH1[_o
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[30m鸭嘴兽[2;37;0m", ({"yazui shou"}));        
        set("gender", "女性");                
        set("unit", "头");
        set("long", "鸭嘴
它是静香的坐骑。
");
        set_temp("owner_id", "ghost");
        set_temp("owner_name", "静香");
        ::setup();
}

