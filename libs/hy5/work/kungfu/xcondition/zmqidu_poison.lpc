#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "忽然一阵刺骨的奇痛袭来，你中的唐门的子母飞针之毒发作了！\n" NOR );
      message("vision", me->name() + "的身子突然晃了两晃，脸上一阵扭曲,好像万分痛苦。\n",
            environment(me), me);
   }
if (me->query("qi") >200)
      me->receive_wound("qi",185 + random(10));
if (me->query("jing") >200)
      me->receive_wound("jing", 180);
      me->add("neili",-me->query("neili")/10);
      me->start_busy(3);
      me->apply_condition("zmqidu_poison", duration - 1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
