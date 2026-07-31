// SN:X]A0LWmQLmQNK:2U
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m云豹[2;37;0m", ({"yun bao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "一头可爱的小豹子。
它是天空的坐骑。
");
        set_temp("owner_id", "monitor");
        set_temp("owner_name", "天空");
        ::setup();
}

