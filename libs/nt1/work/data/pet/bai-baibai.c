// SN:ld^Lbc]QXN31kjJc
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m百[1;31m败[1;37m狮[2;37;0m", ({"baibai shi"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "$HIC$百$HIR$败$HIW$百$HIB$战
它是慕容小涯的坐骑。
");
        set_temp("owner_id", "bai");
        set_temp("owner_name", "慕容小涯");
        ::setup();
}

