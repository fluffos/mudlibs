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
      tell_object(me, HIR "忽然一阵至命的奇热袭来，你中的唐门的霹雳镖之毒发作了！\n" NOR );
      message("vision", me->name() + "的身子突然晃了两晃，脸上一阵扭曲,好像万分痛苦。\n",
            environment(me), me);
   }
      me->receive_wound("qi",me->query("qi")/15);
      if (me->query("jing") >100)
      me->receive_wound("jing", 80);
      me->start_busy(2);
      if (me->query("neili") >100)
      me->add("neili",-50);
      me->apply_condition("tmpili_poison", duration - 1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
