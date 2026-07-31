// SN:_Q`T\oS^RMKL6M8o
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m神马[2;37;0m", ({"shen ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "神马
它是慕容容慕的坐骑。
");
        set_temp("owner_id", "rongmu");
        set_temp("owner_name", "慕容容慕");
        ::setup();
}

