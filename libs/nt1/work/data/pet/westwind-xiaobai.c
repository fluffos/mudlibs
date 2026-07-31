// SN:`8d]CPLXH7<N;l]c
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m白马[2;37;0m", ({"xiaobai ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "$HIW$白马啸西风
它是虚西的坐骑。
");
        set_temp("owner_id", "westwind");
        set_temp("owner_name", "虚西");
        ::setup();
}

