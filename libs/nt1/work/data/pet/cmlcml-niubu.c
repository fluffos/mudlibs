// SN:EZcTR04152C;\][I
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("牛不羊[2;37;0m", ({"niubu yang"}));        
        set("gender", "女性");                
        set("unit", "头");
        set("long", "@_@.
它是陈林的坐骑。
");
        set_temp("owner_id", "cmlcml");
        set_temp("owner_name", "陈林");
        ::setup();
}

