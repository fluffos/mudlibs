// SN:iHOSoU=\Tio@^nHJ
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m小小雕[2;37;0m", ({"fadais diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "再看啄死你^_^
它是发呆的坐骑。
");
        set_temp("owner_id", "fadai");
        set_temp("owner_name", "发呆");
        ::setup();
}

