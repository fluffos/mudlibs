// SN:OPfVD;\8oOM^OLEa
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m怒狮[2;37;0m", ({"nuhuo shi"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "一个发怒的狮子
它是战歌的坐骑。
");
        set_temp("owner_id", "orc");
        set_temp("owner_name", "战歌");
        ::setup();
}

