// SN::8_DlTlYOF]N97W<
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m银月貂[2;37;0m", ({"yinyue diao"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "爱佳漂亮的小宠物
它是爱佳的坐骑。
");
        set_temp("owner_id", "aika");
        set_temp("owner_name", "爱佳");
        ::setup();
}

