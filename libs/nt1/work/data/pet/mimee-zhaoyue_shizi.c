// SN:Hkfm]PgDN7V;dUVN
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m照月狮子马[2;37;0m", ({"zhaoyue_shizi ma"}));        
        set("gender", "女性");                
        set("unit", "匹");
        set("long", "$HIW$传说中月神的战马，神俊无比。
它是小达子的坐骑。
");
        set_temp("owner_id", "mimee");
        set_temp("owner_name", "小达子");
        ::setup();
}

