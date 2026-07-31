// xiyanling.c 圣火令法「吸焰」令

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("遏制攻击只能对战斗中的对手使用。\n");
	else
if (!objectp(weapon = target->query_temp("weapon")))
return notify_fail("对手并没有使用武器。\n");
//      if (!objectp(weapon = target->query_temp("weapon"))
//		return notify_fail("对手没有使用武器，你使出这招后自感象个傻瓜。\n");

//	if (!objectp(weapon = me->query_temp("weapon"))
//		|| (string)weapon->query("skill_type") != "sword"
//			return notify_fail("你使用的武器不对。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
		
	if( (int)me->query_skill("shenghuo-ling", 1) < 40 )
		return notify_fail("你的圣火令法不够娴熟，使不出「吸焰」令。\n");

	msg = HIG "$N使出圣火令法「吸焰」令，连递数个鬼魅的招式企图夺下$n手中的兵器。\n";

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
		msg += HIR " 结果$p被$P攻了个措手不及！\n" NOR;
		target->start_busy( (int)me->query_skill("taiji-jian") / 40 +2 );
	} else {
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
