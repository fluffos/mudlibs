// SN:C7bF\SE1aTK;10HS
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[35m紫骝马[2;37;0m", ({"ziliu ma"}));        
        set("gender", "女性");                
        set("unit", "匹");
        set("long", "xren
它是闲人的坐骑。
");
        set_temp("owner_id", "xren");
        set_temp("owner_name", "闲人");
        ::setup();
}

