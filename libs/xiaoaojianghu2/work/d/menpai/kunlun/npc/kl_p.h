//  kl_p.h
//  Ffox    98-9-9 14:34

inherit NPC;
#include <kunlun.h>

string about_here()
{
    return ("此处是地处昆仑山脉腹地的三圣坳，一直是昆仑派所辖的地盘。");
}

int refuse_killing(object me)
{
    command("heng");
    me->apply_condition("kill_kunlun", 
        me->query_condition("kill_kunlun")+30 );
    return 0;
}
