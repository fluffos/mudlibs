// SN:koZonPA==09bjXK4
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m羊羊羊[2;37;0m", ({"yangyang yang"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "三羊开泰
它是扑通的坐骑。
");
        set_temp("owner_id", "putong");
        set_temp("owner_name", "扑通");
        ::setup();
}

