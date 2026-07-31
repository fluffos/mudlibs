#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   
      tell_object(me, HIR "你只觉丹田如被火炙，内力乱流，烧得你整个身子发烫！\n" NOR );
      tell_room(environment(me), HIR + me->name()+"突然大叫一声，两眼翻白，摔倒在地不住地哀号！\n" NOR,
                ({ me }));     
      if( me->query("max_neili", 1) < 1 ) {
                me->set_temp("last_damage_from", "被化功大法化尽丹元");
                me->die();
                return 0;
        }
      me->receive_damage("qi", 25);
      me->receive_wound("jing", 5);
      me->add("max_neili", - (2 + random(3)));    
	me->add_busy(2); 
	if( duration < 2 ) return 0;
      me->apply_condition("huagong", duration - 1);
   return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
