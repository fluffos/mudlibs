// SN:WW9An<lGT_kk4TTj
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m孤鹤鹤[2;37;0m", ({"gudu he"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "白云深处一孤鹤
它是慕容痴的坐骑。
");
        set_temp("owner_id", "huo");
        set_temp("owner_name", "慕容痴");
        ::setup();
}

