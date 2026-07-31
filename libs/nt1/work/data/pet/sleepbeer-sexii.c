// SN:fOCPHjlXSH;Ui<de
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("云中鹤[2;37;0m", ({"sexii he"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "道姑的鹤
它是紫萱的坐骑。
");
        set_temp("owner_id", "sleepbeer");
        set_temp("owner_name", "紫萱");
        ::setup();
}

