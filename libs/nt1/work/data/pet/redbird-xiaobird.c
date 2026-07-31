// SN:PkdT0Vin^JMbD\PW
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("不死雕[2;37;0m", ({"xiaobird diao"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "这是从火山中飞出的鸟
它是朱雀的坐骑。
");
        set_temp("owner_id", "redbird");
        set_temp("owner_name", "朱雀");
        ::setup();
}

