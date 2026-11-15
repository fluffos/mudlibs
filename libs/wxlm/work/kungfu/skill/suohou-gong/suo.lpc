// suo.c 琐喉


#include <combat.h>

inherit F_SSERVER;

string query_name() { return "锁喉功"; }

int perform(object me, object target)
{
	int damage;
	string msg;
	string pmsg;
	string *limbs;
	string  limb;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (userp(me) && ! me->query("can_perform/suohou-gong/suo"))
		return notify_fail("你现在还不会使用「琐喉」这一招！\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail("琐喉只能在战斗中对对手使用。\n");

	if (objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用琐喉！\n");
		
	if ((int)me->query_skill("suohou-gong", 1) < 140)
		return notify_fail("你的琐喉功还不够娴熟，不能使用琐喉。\n");
				
	if ((int)me->query("neili", 1) < 200)
		return notify_fail("你现在内力太弱，不能使用琐喉。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "冷笑一声，飞身一跃而起，眼露凶光，右手陡然抓"
	      "向$n" HIY "的喉部。"NOR"\n";
	me->add("neili", -20);

	me->want_kill(target);
	ap = me->query_skill("claw");
	dp = target->query_skill("dodge");
	if (ap / 2 + random(ap / 2) > dp)
	{
		me->start_busy(2);
		me->add("neili", -180);
		damage = 0;

		if (me->query("max_neili") > target->query("max_neili") * 2)
		{
			msg += HIR "结果只听“喀喀”几声脆响，$N" HIR "五指已将$n"
			       HIR "喉结捏个粉碎，$n" HIR "一声哀嚎，软绵绵的瘫了下去。"NOR"\n";
			damage = -1;
		} else
		{
			damage = ap + me->query_skill("force");
			damage = ap + random(ap / 2);
			
			if (arrayp(limbs = target->query("limbs")))
				limb = limbs[random(sizeof(limbs))];
			else
				limb = "要害";
			pmsg = HIC "$n连忙腾挪躲闪，只听“喀嚓”一声，$N"
			       HIC "五指正拿中$n" HIC "的" + limb + "，$n"
			       HIC "一声惨叫，鲜血飞溅而出。"NOR"\n";
			msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 66, pmsg);
		}
	} else 
	{
		me->start_busy(2);
		msg += CYN"可是$p看破了$P的企图，身形急动，躲开了这一抓。"NOR"\n";
	}

	message_combatd(msg, me, target);
	if (damage < 0) target->die(me);

	return 1;
}
