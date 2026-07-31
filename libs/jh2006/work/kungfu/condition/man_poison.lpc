#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{         

     tell_object(me, HIB "你突然觉得微微头晕，浑身无力，无法再凝聚内息！\n" NOR );
      tell_room(environment(me), HIB + me->name()+"面色苍白，眼神紊乱，脚下跌跌撞撞！\n" NOR,                
      ({ me }));             
    me->receive_damage("qi", 25);      
    me->receive_wound("jing", 25);
    me->set_temp("last_damage_from", "中蔓陀萝花毒");      
    me->apply_condition("man_poison", duration - 1);   
    if( duration < 1 ) return 0;   
    return CND_CONTINUE;
}
 
string query_type(object me)
{
	return "poison";
}
