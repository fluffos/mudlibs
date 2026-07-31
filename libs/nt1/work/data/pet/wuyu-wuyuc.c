// SN:4?b[61T<;XIY^@;8
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m风[1;36m住[1;37m尘[1;31m香花虎[2;37;0m", ({"wuyuc hu"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "風住塵香花已盡，日晚倦梳頭。
它是很多鱼的坐骑。
");
        set_temp("owner_id", "wuyu");
        set_temp("owner_name", "很多鱼");
        ::setup();
}

