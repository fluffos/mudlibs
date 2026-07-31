// SN:aMm=8dBonc5bCN32
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m白龙马[2;37;0m", ({"longma ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "这是一匹$HIW$白龙化成的白马。
它是啊龙的坐骑。
");
        set_temp("owner_id", "elf");
        set_temp("owner_name", "啊龙");
        ::setup();
}

