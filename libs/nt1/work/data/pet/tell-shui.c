// SN:8S3GCnm_>[S^<?0l
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;34m水虎虎[2;37;0m", ({"shui hu"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "none
它是说三道四的坐骑。
");
        set_temp("owner_id", "tell");
        set_temp("owner_name", "说三道四");
        ::setup();
}

