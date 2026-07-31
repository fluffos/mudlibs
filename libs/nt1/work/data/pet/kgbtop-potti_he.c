// SN:3mTlaTQMBRFI@>V]
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("疾风鹤鹤[2;37;0m", ({"potti_he he"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "疾风鹤
它是澄觉的坐骑。
");
        set_temp("owner_id", "kgbtop");
        set_temp("owner_name", "澄觉");
        ::setup();
}

