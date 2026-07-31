// SN:G9a>fl<SAJgifA2a
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m疯[1;36m狂[1;34m战[1;31m士兽[2;37;0m", ({"bbs shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "$HIG$强大的一只兽
它是听雨轩的坐骑。
");
        set_temp("owner_id", "quest");
        set_temp("owner_name", "听雨轩");
        ::setup();
}

