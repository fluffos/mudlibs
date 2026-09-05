// benlei.c 奔雷
// by hubo 2008-4-27

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("奔雷只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用奔雷！\n");		
				
  if( (int)me->query("neili", 1) < 1000 )
		return notify_fail("你现在内力太弱，不能使用奔雷。\n");
			
	msg = HIR "$N一叫丹田汇元气，真气灌于双掌，大吼一声，如炸雷一般巨响，直拍$n要害。\n"NOR;

	if (random(me->query_skill("strike")) > target->query_skill("dodge")/2 )
	  {
		     me->start_busy(1);

		    target->set("neili",1);
		    me->add("neili", -1000);
		
	      msg += HIY"结果$n被$N的双掌击中，只感觉胸中烦闷，内力荡然无存，大喊一声：我命休矣！！！\n"NOR;
        			
	  } 
	else 
	  {
		  me->start_busy(3);
	  	msg += HIM"$p轻飘飘荡了出去，冷笑道：小儿科的玩意上不了台面的。\n"NOR;
	  }
	
	message_vision(msg, me, target);

	return 1;
}

