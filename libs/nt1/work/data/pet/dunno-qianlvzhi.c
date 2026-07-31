// SN:?1bCYJ\gGB9DDA^=
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("千驴之驴[2;37;0m", ({"qianlvzhi lv"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "哇噻
它是自己爷爷的坐骑。
");
        set_temp("owner_id", "dunno");
        set_temp("owner_name", "自己爷爷");
        ::setup();
}

