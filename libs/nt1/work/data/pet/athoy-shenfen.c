// SN:jY1ehfESh^20V@G_
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m追风雕雕[2;37;0m", ({"shenfen diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "$HIW$一只金眼神雕
它是神游的坐骑。
");
        set_temp("owner_id", "athoy");
        set_temp("owner_name", "神游");
        ::setup();
}


