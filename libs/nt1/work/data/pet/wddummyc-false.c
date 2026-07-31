// SN:I=[PcGR8=@lAge7o
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m假象[2;37;0m", ({"false xiang"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "不是真的象
它是和平药房的坐骑。
");
        set_temp("owner_id", "wddummyc");
        set_temp("owner_name", "和平药房");
        ::setup();
}

