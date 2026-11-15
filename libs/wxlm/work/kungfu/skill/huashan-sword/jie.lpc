// jie.c 华山剑法「截手式」



inherit F_SSERVER;

string query_name() { return "截手式"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	int level;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("华山剑法「截手式」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
		
	if ((level = me->query_skill("huashan-sword", 1)) < 60)
		return notify_fail("你的华山剑法不够娴熟，不会使用「截手式」。\n");

	if (me->query("neili") < 80)
		return notify_fail("你现在真气不够，无法使用「截手式」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "但见$N" HIW "长剑一勒，使出华山剑法绝技之"
	      "“截手式”，转折之际天衣无缝，\n一剑既出，后着"
	      "源源倾泻，如大浪跃滩，层层叠叠，迅然扑向$n"
	      HIW "！"NOR"\n";

	me->add("neili", -50);
	if (random(level) > (int)target->query_skill("parry", 1) / 2)
	{
		msg += HIR "结果$p" HIR "瘁不及防，连连倒退"
		       "几步，一时间无法回手！"NOR"\n";
		target->start_busy(level / 22 + 2);
	} else
	{
		if (objectp(weapon = target->query_temp("weapon")))
			msg += CYN "但是$p" CYN "识破了$P" CYN "的用意，"
			       "自顾将手中的" + weapon->name() +
			       CYN "舞成一团光花，$P"
			       CYN "一怔之下再也攻不进去。"NOR"\n";
		else
			msg += CYN "但是$p" CYN "双手戳点刺拍，将$P"
			       CYN "的来招一一架开。"NOR"\n";

		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
