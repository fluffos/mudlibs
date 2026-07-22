// dart_limit.c
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
   if (duration < 1) return 0;
   me->apply_condition("jobshadi_failed", duration - 1);

   if( duration == 2 && me->query("guo_shoucheng/failed"))
   {
         message_vision(CYN"\n一名宋兵跑过来对$N说道：蒙古靼子又开始进攻了，"
         +"元帅叫你立刻前去待命！\n"NOR,me);
         me->delete("guo_shoucheng/failed");
         me->apply_condition("jobshadi_failed",0);
         return 0;
   }

   return CND_CONTINUE;      
}
