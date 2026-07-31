// SN:oY=4dX;F`gY[DBEK
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("老豹[2;37;0m", ({"lao bao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "老豹
它是王保长的坐骑。
");
        set_temp("owner_id", "mam");
        set_temp("owner_name", "王保长");
        ::setup();
}

