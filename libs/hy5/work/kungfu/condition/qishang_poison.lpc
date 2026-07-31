#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    string msg;
   int damage,damage2;
damage=me->query("qi")/8;
damage2=me->query("jing")/8;
if (damage > 5000) damage=5000;   
if (damage2 > 5000) damage2=5000;   	
msg = HIR"$N脸色一变 吐出一口鲜血！ "NOR;
      switch(random(5)){
      case 0 : 
              msg = HIR"$N突然脚下一慢，好象大腿的穴道被封住了！\n"NOR;
              me->start_busy(3);
              break;
      case 1 : 
              msg = HIR"$N突然眉头一皱，好象是受了内伤！\n"NOR;
              me->receive_damage("qi", damage);
              me->receive_wound("qi", damage);
              break;
      case 2 : 
              msg = HIR"$N的身子突然晃了两晃，好象是中了阴毒的内伤！\n"NOR;
              me->add("neili", -damage*2);
              break;
      case 3 : 
              msg = HIR"$N突然脚下一晃，好象是受了暗伤！\n"NOR;
              me->receive_damage("jing", damage2);
              me->receive_wound("jing", damage2);
              break;
      case 4 : 
              msg = HIR"$N脚下恍惚，精神不能集中，好象是中了内伤！\n"NOR;
              me->add("max_neili", -5);
              break;
      }
      me->start_busy(3);
      if (userp(me))
      {
      message_vision(msg, me);     
      }
      else
      {
        message("vision", me->name() + "脸色一变 吐出一口鲜血,看来是七伤拳拳劲发作了。\n", environment(me), me);
      }
    //message("vision", msg, environment(me), me);
      me->apply_condition("qishang_poison", duration - 1);
      if( duration < 1 ) return 0;
      return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
