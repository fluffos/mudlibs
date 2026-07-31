// SN:mOiZ]a>9=CAA[?WO
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m六[1;35m花[1;36m马[2;37;0m", ({"liuhua ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "真是一匹不错的坐骑。
它是段玉兰的坐骑。
");
        set_temp("owner_id", "gfcs");
        set_temp("owner_name", "段玉兰");
        ::setup();
}

