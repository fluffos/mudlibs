// duo.c 圣火令法「吸焰」令

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon,weapon2;
	string msg;
	int    iDuo;

	weapon2 = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("圣火令法「吸焰」令只有在战斗中施用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if (!objectp(weapon = target->query_temp("weapon")))
		return notify_fail("对方手中没有武器，你使出这招「吸焰令」后自觉象个傻瓜。\n");


	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
		
	if( (int)me->query_skill("shenghuo-ling", 1) < 50 )
		return notify_fail("你的圣火令法不够娴熟，使不出「吸焰」令。\n");

	msg = HIY"$N使出圣火令法「吸焰」令，连递数个鬼魅般的招式向$n的手腕缠绕。\n"NOR;

	me->start_busy(1);

	if( (string)weapon2->query("id") == "shenghuo-ling" ) 
		iDuo = 4 ;
	else 
		iDuo =3 ;

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/iDuo ) {

		msg += HIR"$n顿时觉得双手运作不灵，忽然手腕一麻，手中";
		msg += weapon->name();
		msg += "竟然不易而飞！\n";
		msg += "细看时，已被$N收纳入了怀中！\n"NOR;

		target->start_busy(2);
                weapon->move(environment(me));
//		weapon->move(me);
	} else {
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
	}


	message_vision(msg, me, target);

	return 1;
}
