// SN:Dc`6AGGPOj;fTfHa
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;33m色狼[2;37;0m", ({"color lang"}));        
        set("gender", "男性");                
        set("unit", "条");
        set("long", "我是一只大色狼，一只大色狼～～～～
它是樱叶的坐骑。
");
        set_temp("owner_id", "leaf");
        set_temp("owner_name", "樱叶");
        ::setup();
}

