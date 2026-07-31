// SN:YX>>hSUDSoXg^Ldg
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m飞飞虎[2;37;0m", ({"feifei hu"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "一只会飞的老虎.....真的会飞啦...没骗你.. >.< ..
它是梅超风的坐骑。
");
        set_temp("owner_id", "mcf");
        set_temp("owner_name", "梅超风");
        ::setup();
}

