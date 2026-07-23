// duanjia-sword.c  段家剑 惊天一击

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「惊天一击」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
		
	if( (int)me->query_skill("duanjia-sword", 1) < 70 )
		return notify_fail("你的段家剑法不够娴熟，不会使用。\n");
	                        
	if( (int)me->query_skill("kurong-changong", 1) < 70 )
		return notify_fail("你的枯荣禅功修为不够高。\n");
			
	if( (int)me->query("neili") < 300 )
		return notify_fail("你现在内力太弱，不能使用「惊天一击」。\n");
			
        msg = HIM "$N一跃而起"NOR"，"HIM"手腕一抖"NOR"，"HIM"挽出一个"YEL"美丽"HIM"的剑花"NOR"，"HIM"飞向$n"NOR"。\n"NOR;

	if (random(me->query_skill("force")) > target->query_skill("force")/4 )
	{
		
		damage = (int)me->query_skill("kurong-changong", 1);
		damage = damage +  (int)me->query_skill("duanjia-sword", 1);
		damage = damage +  (int)me->query_skill("sword", 1);

		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/2);
		me->add("neili", -300);
                msg += HIW"只见$N人剑合一"NOR"，"HIW"穿向$n"NOR","HIW"$n只觉一股热流穿"HIR"心"HIW"而过"NOR"，"HIW"喉头一甜"NOR"，"HIR"鲜血"HIW"狂喷而出！\n"NOR;;
                me->start_busy(1);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);

	} else 
	{
		msg += NOR"可是$n猛地向边上一跃,跳出了$N的攻击范围。\n"NOR;
		me->add("neili", -100);
                me->start_busy(1);
		message_combatd(msg, me, target);
	}


	return 1;
}
