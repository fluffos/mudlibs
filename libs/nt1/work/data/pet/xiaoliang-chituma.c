// SN:chJh8T7`73MjM1_e
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("赤兔马[2;37;0m", ({"chituma ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "小亮的朋友
它是小亮的坐骑。
");
        set_temp("owner_id", "xiaoliang");
        set_temp("owner_name", "小亮");
        ::setup();
}

