// SN:C_<kd;k87@nHS>AU
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[37m我的小毛驴[2;37;0m", ({"beggers lv"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "嘿嘿
它是小叫花的坐骑。
");
        set_temp("owner_id", "begger");
        set_temp("owner_name", "小叫花");
        ::setup();
}

