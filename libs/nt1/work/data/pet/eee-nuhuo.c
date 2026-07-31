// SN:YS:>YWAFcL2YnBiD
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m怒豹[2;37;0m", ({"nuhuo bao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "一只生气中的豹子.
它是恶恶恶的坐骑。
");
        set_temp("owner_id", "eee");
        set_temp("owner_name", "恶恶恶");
        ::setup();
}

