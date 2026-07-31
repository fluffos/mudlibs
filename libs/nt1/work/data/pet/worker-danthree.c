// SN:>daEJ4\5NU@>7iCQ
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m药驴[2;37;0m", ({"danthree lv"}));        
        set("gender", "女性");                
        set("unit", "头");
        set("long", "炼丹专用的驴子
它是桃花工人的坐骑。
");
        set_temp("owner_id", "worker");
        set_temp("owner_name", "桃花工人");
        ::setup();
}

