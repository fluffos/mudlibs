// SN:5o\mddeZG:4^aa=4
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m仙鹤[2;37;0m", ({"xhe he"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "灵山中守卫仙草的仙鹤,吸取了天地灵气,日月之精华.
它是慕容霜月的坐骑。
");
        set_temp("owner_id", "syue");
        set_temp("owner_name", "慕容霜月");
        ::setup();
}

