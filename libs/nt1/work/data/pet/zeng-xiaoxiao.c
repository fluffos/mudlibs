// SN:FcU]:?i;TG2UTk9N
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m小马[2;37;0m", ({"xiaoxiao ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "╭∩╮（︶︿︶）╭∩╮
它是水水的坐骑。
");
        set_temp("owner_id", "zeng");
        set_temp("owner_name", "水水");
        ::setup();
}

