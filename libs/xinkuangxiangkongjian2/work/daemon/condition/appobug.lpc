#include <ansi.h>
int update_condition(object me, int duration)
{
if(duration==0) 
return 0;
if(me->is_fighting())
me->start_busy(1);
me->receive_wound("kee",500);
me->receive_damage("kee",500);
if(me->query("force")<0) me->set("force",0);
me->apply_condition("appobug",duration-1);
if(duration<1) return 0;
return 1;
}
