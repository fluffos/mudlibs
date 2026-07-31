// SN:H@L_87_i[JVVjdB9
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("骆驼[2;37;0m", ({"luo tuo"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "$HIW$骆驼而已
它是走四方的坐骑。
");
        set_temp("owner_id", "eswn");
        set_temp("owner_name", "走四方");
        ::setup();
}

