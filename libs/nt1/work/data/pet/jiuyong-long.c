// SN:Xc79:>F7`HRYLV<L
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m白龙驹[2;37;0m", ({"long ju"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "大燕皇帝坐骑,全身毛色如雪，非凡间之物！
它是慕容复燕的坐骑。
");
        set_temp("owner_id", "jiuyong");
        set_temp("owner_name", "慕容复燕");
        ::setup();
}

