// SN:0UIcFGH__gm?\RJK
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[33m老虎[2;37;0m", ({"neweris hu"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "^_^
它是叫什么啊的坐骑。
");
        set_temp("owner_id", "neweri");
        set_temp("owner_name", "叫什么啊");
        ::setup();
}

