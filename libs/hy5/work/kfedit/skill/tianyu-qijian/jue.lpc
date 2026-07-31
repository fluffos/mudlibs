// yu.c  闪剑诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「闪剑诀」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	if ((int)me->query_skill("tianyu-qijian", 1) < 60)
		return notify_fail("你的天羽奇剑不够娴熟，不会使用闪剑诀。\n");

	if ((int)me->query_skill("force") < 90)
		return notify_fail("你的内功实在太差，没法用「闪剑诀」。\n");

	if ((int)me->query("neili", 1) < 300)
		return notify_fail("你现在内力太弱，不能使用「闪剑诀」。\n");
			
        if (me->query_skill_mapped("sword") != "tianyu-qijian")
                return notify_fail("你没有激发天羽奇剑，没法用「闪剑诀」。\n");


	msg = HIY "$N" HIY "身子微微一动，手腕一探，一道剑光疾电般刺向$n。\n" NOR;
	me->add("neili", -70);

	if (random(me->query("combat_exp")) > target->query("combat_exp") / 3)
	{
		target->start_busy((int)me->query_skill("tianyu-qijian", 1) / 50 + 3);
		msg += HIR "$n" HIR "大吃一惊，慌忙招架，这一下便失了先机！\n" NOR;
	} else 
	{
		msg += CYN "可是$p" CYN "不慌不忙，看破了此招"
                       "虚实，并没有受到半点影响。\n" NOR;
		me->add("neili", -100);
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
