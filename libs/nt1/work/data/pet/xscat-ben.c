// SN:IYMlhCf>:TQf7X2B
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m笨驴[2;37;0m", ({"ben lv"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "这是一头笨的不能再笨的笨笨驴!
它是破烂王的坐骑。
");
        set_temp("owner_id", "xscat");
        set_temp("owner_name", "破烂王");
        ::setup();
}

