// SN:`:3;TXd`JTHDoSbH
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m白马[2;37;0m", ({"sha ma"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "一个白马
它是欧阳明月的坐骑。
");
        set_temp("owner_id", "xunfei");
        set_temp("owner_name", "欧阳明月");
        ::setup();
}

