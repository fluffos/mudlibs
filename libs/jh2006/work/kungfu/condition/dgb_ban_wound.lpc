// this condition used by dagou-bang's perform ban。
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
   	if (duration < 1) {
          	message_vision(HIC"$N长出一口气，感觉脚伤好多了。\n" NOR, me);
          	me->add_temp("apply/dodge",(int)me->query_temp("dgb/ban"));
          	me->delete_temp("dgb/ban");
          	return 0;
    	}
   	if (!duration) return 0;
   	
   	if( !living(me) ) {
          	message_vision(HIB"$N闷哼一声，脚下踉跄，立足不稳。\n" NOR, me); 
       	}
   	
   	else {
          	message_vision(HIB"$N闷哼一声，脚下踉跄，立足不稳。\n" NOR, me); 
       	}
   		me->add_busy(random(2)+2);
   		me->apply_condition("dgb_ban_wound", duration - 1);
   	return CND_CONTINUE;
}

string query_type(object me)
{
        return "wound";
}
