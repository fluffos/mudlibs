// SN:b4LJoaPi_2m0EgBa
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m长毛象[2;37;0m", ({"changmao xiang"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "一头长毛象，据说是西域贡品，也不知主人如何得到的。
它是慕容恪的坐骑。
");
        set_temp("owner_id", "bushiwo");
        set_temp("owner_name", "慕容恪");
        ::setup();
}

