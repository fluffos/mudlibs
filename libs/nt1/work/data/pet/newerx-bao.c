// SN:XkC[7X2ONBn=<DGT
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m汗血宝马[2;37;0m", ({"bao ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "^_^
它是段段的坐骑。
");
        set_temp("owner_id", "newerx");
        set_temp("owner_name", "段段");
        ::setup();
}

