// 千里销魂散.qianli_poison.c
// created by olives@SJ 5/1/2001
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
      message_vision(HIY"$N看起来脚步踉跄，好象喝醉了酒一样，摇摇晃晃。\n"NOR, me);
      if(random(me->query_skill("force")*4+me->query("neili"))>me->query("neili"))
	   me->unconcious();
      else
      	   	me->add_busy(1);
      me->apply_condition("qianli_poison", --duration);
      if( duration < 1 ) return 0;
      return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}
