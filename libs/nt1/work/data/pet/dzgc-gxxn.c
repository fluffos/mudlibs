// SN:a;8o\[;_65TNUKmD
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m宫下杏奈[30m小狐[2;37;0m", ({"gxxn hu"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "desc
它是段造厂的坐骑。
");
        set_temp("owner_id", "dzgc");
        set_temp("owner_name", "段造厂");
        ::setup();
}

