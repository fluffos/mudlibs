// SN:8dD:gKQG?kX]MZF<
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("小兽[2;37;0m", ({"xiao_shou shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "亲切
它是欧阳扣肉的坐骑。
");
        set_temp("owner_id", "alc");
        set_temp("owner_name", "欧阳扣肉");
        ::setup();
}

