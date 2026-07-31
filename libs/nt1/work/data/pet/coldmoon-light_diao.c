// SN:n^>hk`<Ue561IQDL
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m闪电貂貂[2;37;0m", ({"light_diao diao"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "一只可爱的灰白色的小貂儿，动作灵活已极。
它是寒月的坐骑。
");
        set_temp("owner_id", "coldmoon");
        set_temp("owner_name", "寒月");
        ::setup();
}

