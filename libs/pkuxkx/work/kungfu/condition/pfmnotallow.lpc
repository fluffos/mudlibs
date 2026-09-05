//dabei zine Nov 1 2010
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>



int update_condition(object me, int duration)
{
   
   if( duration < 1 ) 
    {
       me->delete_temp("pfmnotallow");
       message_vision(HIR"$N大喝一声，吐尽体内浊气，终于冲破穿心诀的克制！"NOR,me);
       return 0;
    }
   else
   {
       me->apply_condition("pfmnotallow", duration - 1);
       return CND_CONTINUE;
   }
   
}
