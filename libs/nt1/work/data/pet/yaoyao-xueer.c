// SN:=]j43RaJDHVDWjaA
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m血雕[2;37;0m", ({"xueer diao"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "亮丽的羽毛犹如冰雪般的晶莹，与它的主人简直是浑然天成！
它是妖妖的坐骑。
");
        set_temp("owner_id", "yaoyao");
        set_temp("owner_name", "妖妖");
        ::setup();
}

