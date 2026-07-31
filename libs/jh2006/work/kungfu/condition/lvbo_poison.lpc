#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", me->name() + "疼痛难忍，连声呼叫。\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "突然胸中一阵刺痛有如刀割，你中的绿波香露奇毒发作了！\n" NOR );
      message("vision", me->name() + "抽搐成一团，面色忽紫忽青，滚在地上哀号。\n",
            environment(me), me);
   }
      me->receive_damage("qi", random(20)+50);
      if(userp(me))
           me->receive_wound("jing", 30+random(30));
      else me->receive_wound("jing", 50+random(30));      
	me->add_busy(2); 
      me->apply_condition("lvbo_poison", duration - 1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
