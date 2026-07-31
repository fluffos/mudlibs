// SN:VKPbl=U<l6Q]2n>Y
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("花雕[2;37;0m", ({"color diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "移花卫的坐骑！
它是慕容卫的坐骑。
");
        set_temp("owner_id", "guard");
        set_temp("owner_name", "慕容卫");
        ::setup();
}

