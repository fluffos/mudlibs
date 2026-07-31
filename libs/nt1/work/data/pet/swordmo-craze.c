// SN:_jGRa8`\86OdUY6c
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m怒狮[2;37;0m", ({"craze shi"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "$HIR$愤怒
它是段剑的坐骑。
");
        set_temp("owner_id", "swordmo");
        set_temp("owner_name", "段剑");
        ::setup();
}

