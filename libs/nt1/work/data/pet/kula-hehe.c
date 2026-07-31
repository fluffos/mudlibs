// SN:\fAGDk4SOf[W8dGj
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m丹顶鹤[2;37;0m", ({"hehe he"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "我嘿嘿的来嘿嘿的去哟
它是任贤齐的坐骑。
");
        set_temp("owner_id", "kula");
        set_temp("owner_name", "任贤齐");
        ::setup();
}

