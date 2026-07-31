// SN:Dfb>o@ck^K;AA;FQ
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m丹顶鹤[2;37;0m", ({"danding he"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "这是张三丰晚年的坐骑，现在赠予其弟子太极。
它是太极的坐骑。
");
        set_temp("owner_id", "dru");
        set_temp("owner_name", "太极");
        ::setup();
}

