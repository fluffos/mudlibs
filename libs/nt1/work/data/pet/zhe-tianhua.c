// SN:3?:NbnHl=lYDZRSD
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;34m丛林野狼[2;37;0m", ({"tianhua lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "它很乖
它是慕容者的坐骑。
");
        set_temp("owner_id", "zhe");
        set_temp("owner_name", "慕容者");
        ::setup();
}

