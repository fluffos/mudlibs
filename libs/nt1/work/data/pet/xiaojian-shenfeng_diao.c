// SN:3Uj]iMfcP3\P[?f6
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("神风雕雕[2;37;0m", ({"shenfeng_diao diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "一个快速又永远抓不住的雕 
它是小剑的坐骑。
");
        set_temp("owner_id", "xiaojian");
        set_temp("owner_name", "小剑");
        ::setup();
}

