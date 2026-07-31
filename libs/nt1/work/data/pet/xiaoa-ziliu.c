// SN:\bP:`P:FhnVASnhl
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[35m紫遛马[2;37;0m", ({"ziliu ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "$MAG$紫遛
它是小阿妹的坐骑。
");
        set_temp("owner_id", "xiaoa");
        set_temp("owner_name", "小阿妹");
        ::setup();
}

