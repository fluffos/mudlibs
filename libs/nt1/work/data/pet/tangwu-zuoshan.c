// SN:F4:40fURTQ26>9hb
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m座山雕[2;37;0m", ({"zuoshan diao"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "它双目正露出凶光，似乎要扑上来把你撕成碎片。
它是唐五藏的坐骑。
");
        set_temp("owner_id", "tangwu");
        set_temp("owner_name", "唐五藏");
        ::setup();
}

