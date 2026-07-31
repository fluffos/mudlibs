// SN:AL;4;E8m=:mb:O0J
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m屠龙驹[2;37;0m", ({"tulong ju"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "$HIY$传说中这只神驹可以杀死一只龙。
它是段档的坐骑。
");
        set_temp("owner_id", "save");
        set_temp("owner_name", "段档");
        ::setup();
}

