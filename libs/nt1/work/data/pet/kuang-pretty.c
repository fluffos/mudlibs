// SN::]EleieH5GO:[[iH
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m水牛牛[2;37;0m", ({"pretty niu"}));        
        set("gender", "女性");                
        set("unit", "头");
        set("long", "水牛一头,一头水牛.
它是狂澜的坐骑。
");
        set_temp("owner_id", "kuang");
        set_temp("owner_name", "狂澜");
        ::setup();
}

