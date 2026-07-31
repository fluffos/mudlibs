// SN:8kjgfon?RiioHAU8
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m妖媚之狐[2;37;0m", ({"yaomei hu"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "嘿嘿
它是妖媚之眼的坐骑。
");
        set_temp("owner_id", "maymay");
        set_temp("owner_name", "妖媚之眼");
        ::setup();
}

