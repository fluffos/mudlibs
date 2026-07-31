// sl_poison.c
//神龙化骨绵掌之毒
// 星星lywin 2000/6/17


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
      tell_object(me, HIB "突然你觉得全身一阵子乏力，原来你中的化骨绵掌之毒发作了起来！\n" NOR );
      message("vision", me->name() + "的身子突然一阵乏力。\n",
            environment(me), me);
   }
      me->receive_wound("qi",22 + random(10));
      me->receive_wound("jing", 25);
      me->apply_condition("sl_poison", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
