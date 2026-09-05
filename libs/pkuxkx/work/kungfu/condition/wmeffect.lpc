//dabei zine Nov 1 2010
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
   
   if( duration < 1 ) 
    {
       if (me->query_temp("wmeffect"))
       {
           me->add_temp("apply/armor", -(me->query_temp("wmeffect")));
           me->add_temp("apply/dodge", -(me->query_temp("wmeffect")));
           me->delete_temp("wmeffect");
           tell_object(me,"离开古襄阳遗址，你发现自己完全无法回忆起武穆遗书的内容。\n");
       }
       return 0;
    }
   else
   {
       me->apply_condition("wmeffect", duration - 1);
       return CND_CONTINUE;
   }
   
}
