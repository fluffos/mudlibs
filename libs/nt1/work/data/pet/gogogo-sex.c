// SN:E0;WbmD43T7aFeQA
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("云中鹤[2;37;0m", ({"sex he"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "别名锅鹤、玄鹤，属于鹤科，学名为 Grus monacha。
它是笑侠的坐骑。
");
        set_temp("owner_id", "gogogo");
        set_temp("owner_name", "笑侠");
        ::setup();
}

