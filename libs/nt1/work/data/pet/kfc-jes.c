// SN:Dao;3QZH:[4WZ`;f
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[31m笨笨[31m虎[2;37;0m", ({"jes hu"}));        
        set("gender", "男性");                
        set("unit", "只");
        set("long", "它像一只小猫一样的温顺，你一看就喜欢了，骑吧!
它是肯德鸡的坐骑。
");
        set_temp("owner_id", "kfc");
        set_temp("owner_name", "肯德鸡");
        ::setup();
}

