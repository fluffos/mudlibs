// SN:OL0R53?hSBN?bJSK
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;32m神驹[2;37;0m", ({"shen ju"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "灵性十足的千里神驹。
它是欧阳闻浩的坐骑。
");
        set_temp("owner_id", "wenc");
        set_temp("owner_name", "欧阳闻浩");
        ::setup();
}

