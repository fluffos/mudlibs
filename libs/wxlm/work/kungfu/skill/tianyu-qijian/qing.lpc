// qing.c 清思剑


#include <combat.h>

inherit F_SSERVER;

string query_name() { return "清思剑"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「清思剑」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("tianyu-qijian", 1) < 70)
		return notify_fail("你的天羽奇剑不够娴熟，不会使用。\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功实在太差，没法用「清思剑」。\n");

	if ((int)me->query("neili", 1) < 300)
		return notify_fail("你现在内力太弱，不能使用「清思剑」。\n");

	if (me->query_skill_mapped("sword") != "tianyu-qijian")
		return notify_fail("你没有激发天羽奇剑，没法用「清思剑」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIG "$N" HIG "手腕轻轻一抖，手中的" + weapon->name() +
	      HIG "化作一道彩虹，光华眩目，笼罩了$n" HIG "。"NOR"\n";

	if (random(me->query_skill("force")) > target->query_skill("force") / 2)
	{
		damage = (int)me->query_skill("sword") / 2;
		damage = damage + random(damage);

		me->add("neili", -120);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 35,
					   HIR "只见$N" HIR "剑花聚为一线，穿向$n"
					   HIR "，$p" HIR "只觉一股热流穿心而过，"
					   "喉头一甜，鲜血狂喷而出！"NOR"\n");
		me->start_busy(2);
	} else 
	{
		msg += CYN "可是$p" CYN "猛地向前一跃,跳出了$P"
		       CYN "的攻击范围。"NOR"\n";
		me->add("neili", -100);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
