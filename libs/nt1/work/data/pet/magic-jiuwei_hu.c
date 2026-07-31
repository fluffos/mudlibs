// SN:?XD<bYL688_SG<c]
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;35m九尾[1;37m灵狐[2;37;0m", ({"jiuwei_hu hu"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "$HIW$九尾者九命也
它是慕容霜天的坐骑。
");
        set_temp("owner_id", "magic");
        set_temp("owner_name", "慕容霜天");
        ::setup();
}

