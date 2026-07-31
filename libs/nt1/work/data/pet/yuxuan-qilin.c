// SN:VU`>VNlcHm4=<19Y
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m火麒麟兽[2;37;0m", ({"qilin shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "它就是万兽之王，不知何因，下到凡间
它是天涯过客的坐骑。
");
        set_temp("owner_id", "yuxuan");
        set_temp("owner_name", "天涯过客");
        ::setup();
}

