// SN:m6aV_ASoREWl^@1`
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[37m熊熊[2;37;0m", ({"xiong xiong"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "大熊熊
它是欧阳青蛙的坐骑。
");
        set_temp("owner_id", "sana");
        set_temp("owner_name", "欧阳青蛙");
        ::setup();
}

