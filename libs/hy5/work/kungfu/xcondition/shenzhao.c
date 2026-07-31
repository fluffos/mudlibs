#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", HIR "只见"+me->name()+ HIR "呛呛退了数步，身子摇晃，双"
              "腿渐渐弯曲，似乎喝醉了一般。\n" NOR, environment(me), me);
   }
   else {
      tell_object(me, HIB "你只感内息顿滞，真气不畅，一张脸涨得通红，便要跌倒。！\n" NOR );
if (environment(me) &&  me)
{
      message("vision", HIR "只见"+me->name()+ HIR "呛呛退了数步，身子摇晃，双"
              "腿渐渐弯曲，似乎喝醉了一般。\n" NOR,
            environment(me), me);
}
   }
      me->receive_wound("qi",50 + random(100));
      me->receive_wound("jing", 50);
      me->start_busy(2);
      me->apply_condition("shenzhao", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}


