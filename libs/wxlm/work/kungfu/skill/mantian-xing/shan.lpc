// shan.c



inherit F_SSERVER;

string query_name() { return "星光"ZJBR"闪烁"; }

int perform(object me, object target)
{
 int skill;
 
	int my_exp, ob_exp;
	string pmsg;
	string msg;
	object weapon;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("星光闪烁只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("handing")) ||
	    (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你现在手中并没有拿着暗器，怎么施展星光闪烁？\n");

	if (weapon->query_amount() < 3)
		return notify_fail("至少要有三枚暗器你才能施展星光闪烁。\n");

	if ((skill = me->query_skill("mantian-xing", 1)) < 100)
		return notify_fail("你的满天星不够娴熟，不会使用星光闪烁。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你内力不够了。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	me->add("neili", -80);
	weapon->add_amount(-3);

	msg= HIY "$N" HIY "突然纵身向后一个翻滚，就在快落地的一瞬"
	     "间，$n" HIY "陡然发现几点寒光闪烁不定地袭向自己！"NOR"\n";

	me->start_busy(2);
	my_exp = me->query_skill("throwing");
	ob_exp = target->query_skill("dodge");
	if (my_exp / 2 + random(my_exp) > ob_exp)
	{
		msg += HIR "结果$p" HIR "反应不及，中了$P" + HIR "一" +
		       weapon->query("base_unit") + weapon->name() +
		       HIR "！"NOR"\n";
		target->receive_wound("qi", skill / 3 + random(skill / 3), me);
		COMBAT_D->clear_ahinfo();
		weapon->hit_ob(me, target,
			       me->query("jiali") + 120);
		if (stringp(pmsg = COMBAT_D->query_ahinfo()))
			msg += pmsg;
		message_combatd(msg, me, target);
	} else
	{
		msg += HIG "可是$p" HIG "从容不迫，轻巧的闪过了$P" HIG "发出的" +
		       weapon->name() + HIG "。"NOR"\n";
		message_combatd(msg, me, target);
	}

	me->reset_action();
	return 1;
}