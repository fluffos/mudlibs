// feilong.c 华山剑法「追命连环剑」


#include <combat.h>

inherit F_SSERVER;

string query_name() { return "三仙"ZJBR"夺命"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	int damage;
	string msg;
	string tname;
	object weapon;
	int ap, fp, dp, pp;

	if (userp(me) && ! me->query("can_perform/huashan-sword/sanxian"))
		return notify_fail("你不会使用追命连环剑。\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「追命连环剑」只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("不拿剑怎么使用「追命连环剑」？\n");

	if ((int)me->query_skill("huashan-sword", 1) < 135)
		return notify_fail("你华山剑法不够娴熟，使不出「追命连环剑」。\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("你现在真气不够，无法将「追命连环剑」使完！\n");

	if (me->query_skill_mapped("sword") != "huashan-sword")
		return notify_fail("你没有激发华山剑法，无法使用「追命连环剑」。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	tname = target->name();
	me->add("neili", -300);

	ap = me->query_skill("sword");
	fp = target->query_skill("force") + target->query_skill("martial-cognize", 1);
	dp = target->query_skill("dodge") + target->query_skill("martial-cognize", 1);
	pp = target->query_skill("parry") + target->query_skill("martial-cognize", 1);

	msg = HIM "$N" HIM "将内力全都运到了剑上，呼的一剑，当头直劈。"NOR"\n";
	if (ap / 2 + random(ap) < dp)
		msg += CYN "$n" CYN "斜身闪开。"NOR"\n";
	else
	if (ap / 2 + random(ap) < fp)
		msg += CYN "$n" CYN "默运内力，奋力架开$N" CYN "这一击，随即闪开。"NOR"\n";
	else
	{
		damage = ap / 2 + random(ap / 2);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
					   HIR "$n" HIR "急忙后退，竟然躲避不及，被$N"
					   HIR "这一剑震得口吐鲜血，接连后退。"NOR"\n");
	}

	if (objectp(target))
	{
		msg += HIM "\n$N" HIM "圈转" + weapon->name() + HIM "，拦腰横削。"NOR"\n";
		if (ap / 2 + random(ap) < dp)
			msg += CYN "$n" CYN "纵身从剑上越过。"NOR"\n";
		else
		if (ap / 2 + random(ap) < pp)
			msg += CYN "$n" CYN "随手格挡，将$N" CYN "这一剑架开，轻身跃开。"NOR"\n";
		else
		{
			damage = ap + random(ap / 2);
			msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 55,
						   HIR "此招来势当真快及，$n" HIR "哪里来得及闪"
						   "避招架？只见$N" HIR "剑光闪过，$n"
						   HIR "腰间霎时鲜血淋漓！"NOR"\n");
		}
	}

	if (objectp(target))
	{
		msg += HIM "\n$N" HIM "长剑反撩，疾刺$p" HIM "后心。"NOR"\n";
		if (ap / 2 + random(ap) < pp)
			msg += CYN "$n" CYN "身在空中，不及变招，只能挥出一招，正击中$N"
			       CYN "剑上，略一借力，飘然避去。"NOR"\n";
		else
		{
			damage = ap + random(ap / 2);
			msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 66,
						   HIR "$n" HIR "身在空中，哪里来得及变招？只见$N"
						   HIR "此剑掠过，$n" HIR "大声惨呼，鲜血四下飞溅！"NOR"\n");
		}
	}

	me->start_busy(3);
	if (objectp(target))
		message_combatd(msg, me, target);
	else
	{
		msg = replace_string(msg, "$n", tname);
		message_vision(msg, me);
	}

	return 1;
}
