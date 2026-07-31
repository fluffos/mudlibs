// SN:OSWlglF_1dGkG[VR
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m天马[2;37;0m", ({"tuan ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "$HIW$天上飞的小白马
它是慕容无敌的坐骑。
");
        set_temp("owner_id", "mmm");
        set_temp("owner_name", "慕容无敌");
        ::setup();
}

