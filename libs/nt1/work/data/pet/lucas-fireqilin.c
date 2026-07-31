// SN:54A=TcBTAK`dAJV;
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;31m火麒麟神兽[2;37;0m", ({"fireqilin shou"}));        
        set("gender", "男性");                
        set("unit", "头");
        set("long", "咬你哦！~咬你哦！
它是殷真的坐骑。
");
        set_temp("owner_id", "lucas");
        set_temp("owner_name", "殷真");
        ::setup();
}

