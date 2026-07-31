// SN:bOa\aLOSA[?idMlC
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[31m汗血宝马[2;37;0m", ({"bao ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "。。。。。。。。。
它是我是谁的坐骑。
");
        set_temp("owner_id", "woshishui");
        set_temp("owner_name", "我是谁");
        ::setup();
}

