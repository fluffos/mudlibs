// SN:d2CX?4CN2:c\Ice<
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("看眉鹤[2;37;0m", ({"look he"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "看眉
它是小丫丫的坐骑。
");
        set_temp("owner_id", "musi");
        set_temp("owner_name", "小丫丫");
        ::setup();
}

