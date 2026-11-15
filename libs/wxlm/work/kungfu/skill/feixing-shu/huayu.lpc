// huayu.c



inherit F_SSERVER;

string query_name() { return "漫天"ZJBR"花雨"; }

int perform(object me, object target)
{
 int skill;
	int n;
	int my_exp, ob_exp;
	string pmsg;
	string msg;
	object weapon;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("满天花雨只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("handing")) ||
	    (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你现在手中并没有拿着暗器。\n");

	if (weapon->query_amount() < 10)
		return notify_fail("至少要有十枚暗器你才能施展满天花雨。\n");

	if ((skill = me->query_skill("feixing-shu", 1)) < 100)
		return notify_fail("你的飞星术不够娴熟，不会使用满天花雨。\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功火候不够，不能使用满天花雨。\n");

	if ((int)me->query("neili") < 150)
		return notify_fail("你内力不够了。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	me->add("neili", -100);
	weapon->add_amount(-10);

	msg= HIG "只听一股劲风从$N" HIG "的右侧发出，$N" HIG
	     "手中的" + weapon->name() + HIG "如烟雨般向$n"
	     HIG "笼罩过去！\n";

	me->start_busy(2);
	my_exp = me->query_skill("throwing");
	ob_exp = target->query_skill("dodge");
	if (my_exp / 2 + random(my_exp) > ob_exp)
	{
		n = 1 + random(2);
		if (random(my_exp) > ob_exp) n += 1 + random(2);
		if (random(my_exp / 2) > ob_exp) n += 1 + random(2);
		if (random(my_exp / 4) > ob_exp) n += 1 + random(2);
		msg += "结果$p" HIG "反应不及，中了$P" HIG +
		       chinese_number(n) + weapon->query("base_unit") +
		       weapon->name() + HIG "！"NOR"\n";
		target->receive_wound("qi", skill / 3 + random(skill / 3), me);
		while (n--)
		{
			COMBAT_D->clear_ahinfo();
			weapon->hit_ob(me, target,
				       me->query("jiali") + 100 + n * 10);
		}
		if (stringp(pmsg = COMBAT_D->query_ahinfo()))
			msg += pmsg;
		message_combatd(msg, me, target);
	} else
	{
		msg += "可是$p" HIG "躲过了$P" HIG "发出的所有" +
		       weapon->name() + HIG "。"NOR"\n";
		message_combatd(msg, me, target);
	}

	me->reset_action();
	return 1;
}