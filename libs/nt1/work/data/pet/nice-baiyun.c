// SN:443;icb3Y@Y5ZWo;
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m青云鹤[2;37;0m", ({"baiyun he"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "笨鸟
它是繁星的坐骑。
");
        set_temp("owner_id", "nice");
        set_temp("owner_name", "繁星");
        ::setup();
}

