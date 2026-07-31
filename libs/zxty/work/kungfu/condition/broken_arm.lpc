#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", me->name() + "断腕处鲜血不断流出。\n", environment(me), me);
   }
   else {
      tell_object(me, HIR "你断腕处鲜血不断流出，力气不断的减少。\n" NOR );
      message("vision", me->name() + "断腕处鲜血不断流出。\n",
            environment(me), me);
   }
      me->receive_wound("qi", 50);
      me->add_temp("apply/strength",-1);
      if (me->query_str() <0)
              me->add_temp("apply/strength",1);
        me->add_busy(2); 
      me->apply_condition("broken_arm", duration-1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

string query_type(object me)
{
        return "wound";
}


