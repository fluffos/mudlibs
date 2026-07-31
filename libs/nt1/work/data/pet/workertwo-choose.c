// SN:4YVaCGGoGGBi6]Ga
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m药驴[2;37;0m", ({"choose lv"}));        
        set("gender", "女性");                
        set("unit", "头");
        set("long", "炼丹专用的驴子
它是桃花仆人的坐骑。
");
        set_temp("owner_id", "workertwo");
        set_temp("owner_name", "桃花仆人");
        ::setup();
}

