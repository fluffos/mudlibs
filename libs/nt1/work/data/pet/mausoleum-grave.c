// SN:?N2gm85OWUJ<Q>UW
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[35m食尸貂[2;37;0m", ({"grave diao"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "小家伙
它是唐昭陵的坐骑。
");
        set_temp("owner_id", "mausoleum");
        set_temp("owner_name", "唐昭陵");
        ::setup();
}

