// SN:RC=[eb4^h1e0\3Q;
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m闪电貂[2;37;0m", ({"shandian diao"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "唐乐天的坐骑
它是唐乐天的坐骑。
");
        set_temp("owner_id", "gutianle");
        set_temp("owner_name", "唐乐天");
        ::setup();
}

