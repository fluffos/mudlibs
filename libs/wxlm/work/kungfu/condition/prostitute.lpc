// prostitute.c
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if (duration < 1) return 0;
   if (file_name(environment(me))!="/d/city/lichunyuan2")
   {
   tell_object(me,HIY"观乐楼保卫出现在你身边：你能跑哪里去！快回去！"NOR"\n");
      message_vision(CYN"观乐楼保卫突然出现，不由分说，拉了$N就走。"NOR"\n",me);
      me->move("/d/city/lichunyuan2");
   }
   me->apply_condition("prostitute", duration - 1);
   return CND_CONTINUE;
}
