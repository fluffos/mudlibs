// dianxue_busy
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{      
      if( duration < 1 ) 
      {
       tell_object(me, HIW "你的穴道终于解开了！\n" NOR );
       return 0;
       }
      //if (!duration) return 0;
      me->apply_condition("dianxue_busy", duration - 1);      
      return CND_CONTINUE;      
}

