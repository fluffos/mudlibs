// ju.c 三花聚顶


#include <combat.h>

inherit F_SSERVER;

string query_name() { return "三花"ZJBR"聚顶"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
 
	int damage;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("三花聚顶只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("haotian-zhang", 1) < 60)
		return notify_fail("你的昊天掌不够娴熟，不会使用三花聚顶。\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功修为不够，难以施展三花聚顶。\n");

	if ((int)me->query("neili") < 150)
		return notify_fail("你现在真气不够，无法使用三花聚顶。\n");

	if (me->query_skill_mapped("strike") != "haotian-zhang")
		return notify_fail("你现在没有激发昊天掌法，无法使用三花聚顶。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "大喝一声，合身向$n" HIC "扑上，双掌"
	      "同时击出，正是一招「三花聚顶」。"NOR"\n";

	if (random(me->query_skill("force")) > target->query_skill("force") / 2)
	{
		me->start_busy(2);
		me->add("neili", -110);
		damage = me->query_skill("strike");
		damage = damage / 3 + random(damage / 3);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
					   HIR "结果$p" HIR "被$P" HIR "的气势所"
					   "摄，慌忙后退，结果被$P" HIR "一掌击"
					   "了个正中，吐血不止！！"NOR"\n");
	} else
	{
		me->start_busy(3);
		me->add("neili", -60);
		msg += CYN "可是$p" CYN "识破了$P"
		       CYN "这一招，斜斜一跃避开。"NOR"\n";
	}
	message_combatd(msg, me, target);

	return 1;
}