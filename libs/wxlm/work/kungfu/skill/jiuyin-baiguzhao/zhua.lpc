// zhua.c 玄阴炼骨爪 - 九阴神抓


#include <combat.h>

inherit F_SSERVER;

string query_name() { return "九阴"ZJBR"神抓"; }
string *pfm_type() { return ({ "claw", }); }

int perform(object me, object target)
{
	int damage;
	string msg;
	string pmsg;
	string *limbs;
	string  limb;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("九阴神抓只能对战斗中的对手使用。\n");

	if (objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用九阴神抓！\n");
		
	if ((int)me->query_skill("jiuyin-baiguzhao", 1) < 80)
		return notify_fail("你的玄阴炼骨爪还不够娴熟，不能使用九阴神抓。\n");

	if (me->query_skill_mapped("claw") != "jiuyin-baiguzhao")
		return notify_fail("你没有激发玄阴炼骨爪，无法使用九阴神抓。\n");
				
	if ((int)me->query("neili", 1) < 200)
		return notify_fail("你现在内力太弱，不能使用九阴神抓。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "冷笑一声，眼露凶光，右手成爪，三盘两旋虚虚"
	      "实实的向$n" HIR "的头顶抓了下来。"NOR"\n";
	me->add("neili", -20);

	me->want_kill(target);
	ap = me->query_skill("claw");
	dp = target->query_skill("dodge");
	if (ap / 2 + random(ap * 2 / 3) > dp)
	{
		me->start_busy(2);
		me->add("neili", -180);
		damage = 0;

		if (me->query("max_neili") < target->query("max_neili") * 4 / 5 &&
		    me->query_skill("force") < target->query_skill("force"))
			msg += HIY "“啪”的一声$N" HIY "正抓在$n" HIY "的天灵盖上，"
			       "结果震得“哇哇”怪叫了两声！"NOR"\n";
		else
		if (me->query("max_neili") > target->query("max_neili") * 2)
		{
			damage = ap * 5 + (int)me->query_skill("force");

			pmsg = HIY "“扑哧”一声，$N" HIY "五指正插入$n" HIY "的天灵"
			       "盖，$n" HIY "一声惨叫，软绵绵的瘫了下去。"NOR"\n";

			msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 120, pmsg);
		} else
		{
			damage = ap + (int)me->query_skill("force");
			damage = damage / 2 + random(damage / 2);
			
			if (arrayp(limbs = target->query("limbs")))
				limb = limbs[random(sizeof(limbs))];
			else
				limb = "要害";
			pmsg = HIC "$n连忙腾挪躲闪，然而“扑哧”一声，$N"
			       HIC "五指正插入$n" HIC "的" + limb + "，$n"
			       HIC "一声惨叫，血射五步。"NOR"\n";
			msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 66, pmsg);
		}
	} else 
	{
		me->start_busy(2);
		msg += CYN "可是$p" CYN "看破了$P"
		       CYN "的企图，身形急动，躲开了这一抓。"NOR"\n";
	}

	message_combatd(msg, me, target);

	if (! target->is_killing(me))
		target->kill_ob(me);

	return 1;
}

