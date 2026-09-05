inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>



int update_condition(object me, int duration)
{
   
      tell_object(me, HIB "突然你感觉头晕目眩，四肢无力，有一点恶心想吐, 看来是被核辐射了！\n" NOR );
      tell_room(environment(me), HIB + me->name()+"突然头晕目眩，站立不稳，看起来是想吐了！\n" NOR,
                ({ me }));     
  
      me->receive_damage("qi", 100);
      me->receive_damage("jing", 100);
      me->receive_wound("qi", 50);
      me->receive_wound("jing", 50);
      if (me->query_condition("you_poison")>(1+me->query_skill("poison",1)/20))
      me->apply_condition("you_poison", duration - 1 - me->query_skill("poison",1)/20);
      else return 0;
      if( duration < 1 ) return 0;
      return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
