// SN:<B9`Fl950?E_CFD;
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("星星马[2;37;0m", ({"xingxing ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "这个是马吗?
它是欧阳想的坐骑。
");
        set_temp("owner_id", "lianx");
        set_temp("owner_name", "欧阳想");
        ::setup();
}

