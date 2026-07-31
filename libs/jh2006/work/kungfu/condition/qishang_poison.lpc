#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    string msg;
      switch(random(5)){
      case 0 : 
              msg = HIR"$N突然脚下一慢，好象大腿的穴道被封住了！\n"NOR;
              me->add_busy(3);
              break;
      case 1 : 
              msg = HIR"$N突然眉头一皱，好象是受了内伤！\n"NOR;
              me->receive_damage("qi", 100);
              me->receive_wound("qi", 50);
              break;
      case 2 : 
              msg = HIR"$N的身子突然晃了两晃，好象是中了阴毒的内伤！\n"NOR;
              me->receive_damage("neili", 250);
              break;
      case 3 : 
              msg = HIR"$N突然脚下一晃，好象是受了暗伤！\n"NOR;
              me->receive_damage("jing", 50);
              me->receive_wound("jing", 30);
              break;
      case 4 : 
              msg = HIR"$N脚下恍惚，精神不能集中，好象是中了内伤！\n"NOR;
              me->receive_damage("jingli", 150);
              break;
      }
      message_vision(msg, me);      
      me->apply_condition("qishang_poison", duration - 1);
      if( duration < 1 ) return 0;
      return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
