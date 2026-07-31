// kuai.c 「快拳」

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "胡家"ZJBR"快拳"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「快拳」只能对战斗中的对手使用。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
		
	if ((int)me->query_skill("hujia-quan", 1) < 80)
		return notify_fail("你的胡家拳法不够娴熟，不会使用「快拳」。\n");

	if (me->query("neili") < 80)
		return notify_fail("你现在真气不够，无法使用「快拳」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIG "$N" HIG "纵步上前，拳招迭出，霎时向$n"
	      HIG "攻出了数十招。"NOR"\n";

	me->add("neili", -40);
	ap = me->query_skill("cuff");
	dp = target->query_skill("dodge");
	if (ap / 2 + random(ap) > dp)
	{
		msg += HIR "结果$p" HIR "无法分清$P" HIR "招式中的虚实，"
		       "不由手忙脚乱，竭力抵挡！"NOR"\n";
		target->start_busy((int)me->query_skill("cuff") / 25 + 2);
	} else
	{
		msg += CYN "可是$p" CYN "看破了$P" CYN "的虚招，轻轻一闪，"
		       "避开了这暴风骤雨一般拳影。"NOR"\n";
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
