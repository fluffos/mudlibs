// SN:hVnFaAXJ:9]74\=m
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;37m慕容[1;31m艳狐狐[2;37;0m", ({"mry hu"}));        
        set("gender", "女性");                
        set("unit", "只");
        set("long", "一只狐
它是慕容涟漪的坐骑。
");
        set_temp("owner_id", "delphyne");
        set_temp("owner_name", "慕容涟漪");
        ::setup();
}

