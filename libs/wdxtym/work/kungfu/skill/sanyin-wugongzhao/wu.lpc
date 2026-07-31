#include <ansi.h>
#include <combat.h>

#define WU "「" HIR "三阴连抓" NOR "」"

inherit F_SSERVER;
 
string query_name() { return "三阴"ZJBR"连抓"; }

int perform(object me, object target)
{
	string msg;
	int ap, dp;
	int count;
	int i;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail(WU "只能对战斗中的对手使用。\n");

	if (objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能施展" WU "。\n");

	if (me->query_skill_mapped("claw") != "sanyin-wugongzhao")
		return notify_fail("你没有激发三阴爪为空手技能，无法施展" WU "。\n");

	if (me->query_skill_prepared("claw") != "sanyin-wugongzhao")
		return notify_fail("你现在没有准备使用三阴爪，无法施展" WU "。\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 120)
		return notify_fail("你的三阴爪火候不够，无法施展" WU "。\n");

	if ((int)me->query_skill("claw", 1) < 200)
		return notify_fail("你的基本爪法火候不够，无法施展" WU "。\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力修为不足，无法施展" WU "。\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你的真气不够，无法施展" WU "。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "双眼通红，猛提内力，向$n" HIR "连环攻出。"NOR"\n";

	ap = me->query_skill("claw") + me->query("str") * 10;
	dp = target->query_skill("dodge") + target->query("dex") * 10;

	if (ap / 2 + random(ap) > dp)
	{
		count = ap / 10;
		msg += HIR "$n" HIR "面对$P" HIR "这连环攻势，不禁心生惧意，慌乱中破绽迭出。"NOR"\n";
	} else
	{
		msg += HIC "$n" HIC "微一凝神，面对$P" HIC "这攻势却丝毫不乱，小心招架。"NOR"\n";
		count = 0;
	}

	message_combatd(msg, me, target);
	me->add_temp("apply/attack", count);

	me->add("neili", -200);
	if (me->query_skill("hanmo-xuangong", 1) > 49) 
	{
	for (i = 0; i < 8; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, 0, 0);
	}
	me->start_busy(2 + random(7));
	}
	else {
	for (i = 0; i < 6; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, 0, 0);
	}
	me->start_busy(1 + random(6));
	}

	me->add_temp("apply/attack", -count);

	return 1;
}

