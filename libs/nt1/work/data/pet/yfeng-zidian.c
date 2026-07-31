// SN:0ckX0DbYl3MHco;O
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;35m紫[1;37m电[1;32m貂[2;37;0m", ({"zidian diao"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "可爱的小貂，毛皮特别光滑！
它是易沐风的坐骑。
");
        set_temp("owner_id", "yfeng");
        set_temp("owner_name", "易沐风");
        ::setup();
}

