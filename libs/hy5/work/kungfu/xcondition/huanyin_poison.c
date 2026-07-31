// huanyin_poison.c
#include <ansi.h>

int update_condition(object me, int duration)
{
   int damage,damage2;
damage=me->query("qi")/20;
damage2=me->query("jing")/20;
if (damage > 5000) damage=5000;   
if (damage2 > 5000) damage2=5000;   	
	
if ((int)me->query("jing") < 100000)
{
    me->receive_damage("jing", damage2);
    me->receive_wound("jing", damage2);
 }  else    me->receive_wound("jing", damage2);
      me->start_busy(random(3)+1);
if ((int)me->query("qi") < 100000)
{
    me->receive_damage("qi", damage);
    me->receive_wound("qi", damage);
}  else    me->receive_wound("qi", damage);
	
me->start_busy(2);
        me->apply_condition("huanyin_poison", duration - 1);
if (me)
{
        message_vision(HIG "$N" HIG "的痛苦的呻吟了一声，脸上笼"
              "罩了一股淡淡的绿气。\n" NOR, me);
        tell_object(me, HIR "你忽然感到一阵寒气自丹田的而起，逐步渗透到四"
               "肢白赅，透出阵阵寒意。！\n" NOR );
}
        if( duration < 1 ) return 0;
        return 1;
}



