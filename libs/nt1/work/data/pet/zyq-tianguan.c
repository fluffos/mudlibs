// SN:KX9[NSJ_OMm7lVCa
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m北斗天罡狼[2;37;0m", ({"tianguan lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "任独行的座骑
它是任独行的坐骑。
");
        set_temp("owner_id", "zyq");
        set_temp("owner_name", "任独行");
        ::setup();
}

