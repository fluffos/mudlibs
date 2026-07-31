// SN:?@F00QVm=j1R\jPW
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m风魔小次狼[2;37;0m", ({"lang lang"}));        
        set("gender", "女性");                
        set("unit", "条");
        set("long", "一只狼
它是段潇潇的坐骑。
");
        set_temp("owner_id", "machao");
        set_temp("owner_name", "段潇潇");
        ::setup();
}

