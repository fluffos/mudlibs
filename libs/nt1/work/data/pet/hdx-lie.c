// SN:SCgb8B@2T7g@W6WX
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[33m猎豹[2;37;0m", ({"lie bao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "它的速度是无敌的
它是段老二的坐骑。
");
        set_temp("owner_id", "hdx");
        set_temp("owner_name", "段老二");
        ::setup();
}

