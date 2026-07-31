#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "流月"ZJBR"一剑"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;
 
	if (! target) target = offensive_target(me);

	if (userp(me) && ! me->query("can_perform/liuyue-jian/liu"))
		return notify_fail("你现在还不会使用「流月」这一招！\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail("「流月」只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	      (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (me->query_skill("force") < 120)
		return notify_fail("你的内功的修为不够，使不出「流月」这一招！\n");

	if (me->query_skill("liuyue-jian", 1) < 120)
		return notify_fail("你的玉影流月剑法修为不够，使不出「流月」这一招！\n");

	if (me->query("neili") < 250)
		return notify_fail("你的真气不够，使不出「流月」这一招！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "一声清啸，剑法忽变，手中" + weapon->name() + HIY
		  "轻轻划出，带出一条无比绚丽的剑芒，遥指$n" HIY "而去。"NOR"\n";
	ap = me->query_skill("sword");
	dp = target->query_skill("parry");

	if (ap / 2 + random(ap) > dp)
	{
		damage = ap / 2 + random(ap);
		me->add("neili", -150);
		me->start_busy(2);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
					   HIR "$n" HIR "只惊得目瞪口呆，一个不慎，被$N" HIR
					   "精妙的剑招刺中，鲜血飞溅！"NOR"\n");
	} else
	{
		me->add("neili", -60);
		me->start_busy(3);
		msg += CYN "可是$p" CYN "并不慌乱，收敛心神，轻轻格挡开了$P"
		       CYN "的剑招。"NOR"\n";
	}

	message_combatd(msg, me, target);

	return 1;
}

