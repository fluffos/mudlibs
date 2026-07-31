// SN:S>Z5=nE9AfDoM@a?
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m极[1;37m速[1;32m不[1;37m良[1;32m牛[2;37;0m", ({"speed niu"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "嘴上叼著烟斗，鼻粱上挂著一副小墨镜，十足品行不良的小野牛。
它是断武的坐骑。
");
        set_temp("owner_id", "godrod");
        set_temp("owner_name", "断武");
        ::setup();
}


