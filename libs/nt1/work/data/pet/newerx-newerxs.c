// SN:^aeI`m3IYnd@>U0Q
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[33m我的小老虎[2;37;0m", ({"newerxs hu"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "^_^
它是段段的坐骑。
");
        set_temp("owner_id", "newerx");
        set_temp("owner_name", "段段");
        ::setup();
}

