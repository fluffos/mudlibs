// SN:V;LMI8ImOiX1<XZ\
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m说鬼缓[2;37;0m", ({"shuoguihuade hou"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "暗它是小菜菜的坐骑。
");
        set_temp("owner_id", "caicai");
        set_temp("owner_name", "小菜菜");
        ::setup();
}

