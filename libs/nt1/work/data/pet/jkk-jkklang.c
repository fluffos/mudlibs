// SN:EgNUc5XTgia;g\9V
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m斩狼狼[2;37;0m", ({"jkklang lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "血刀
它是斩刀客的坐骑。
");
        set_temp("owner_id", "jkk");
        set_temp("owner_name", "斩刀客");
        ::setup();
}

