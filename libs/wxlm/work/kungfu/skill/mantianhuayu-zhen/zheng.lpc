// zheng.c



inherit F_SSERVER;

string query_name() { return "花雨"ZJBR"金针"; }

string query_txt()
{
	return "要求：手持20枚以上暗器，技能100级，内功激发150，内力150"ZJBR
	"效果：对比自身暗器激发等级和目标轻工激发，同等级1/2概率，对目标造成造成一个技能等级/4--/2之间的一个气上限伤害，同时1-8次暗器击打";
}

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
		return notify_fail("你只能在战斗中对对手掷金针。\n");

	if (! objectp(weapon = me->query_temp("handing")) ||
	    (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你现在手中并没有拿着暗器。\n");

	if (weapon->query_amount() < 20)
		return notify_fail("至少要有二十枚暗器你才能施展花雨金针。\n");

	if ((skill = me->query_skill("mantianhuayu-zhen", 1)) < 100)
		return notify_fail("你的满天花雨掷金针不够娴熟，还不知怎么掷出金针。\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功火候不够，无法掷出金针。\n");

	if ((int)me->query("neili") < 150)
		return notify_fail("你内力不够了。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	me->add("neili", -100);
	weapon->add_amount(-10);

	msg= HIY "$N" HIY "飞身跃起，右手一张，顿时洒出一片金芒，"
	     "手中" + weapon->name() + HIY "如急风暴雨一般直射$n"
	     HIY "而去！"NOR"\n";

	me->start_busy(2);
	my_exp = me->query_skill("throwing");
	ob_exp = target->query_skill("dodge")/2;
	if (random(my_exp) > ob_exp/2)
	{
		n = 1 + random(2);
		if (random(my_exp) > ob_exp) n += 1 + random(2);
		if (random(my_exp / 2) > ob_exp) n += 1 + random(2);
		if (random(my_exp / 4) > ob_exp) n += 1 + random(2);
		msg += HIR "结果$p" HIR "一声惨嚎，连中了$P" HIR "发出的" HIR + chinese_number(n) + weapon->query("base_unit") +
		       weapon->name() + HIR "。"NOR"\n";
		target->receive_wound("qi", skill / 4 + random(skill / 4), me);
		while (n--)
		{
			COMBAT_D->clear_ahinfo();
			weapon->hit_ob(me, target,me->query("jiali") + 100 + n * 10);
		}
		if (stringp(pmsg = COMBAT_D->query_ahinfo()))
			msg += pmsg;
		message_combatd(msg, me, target);
	} else
	{
		msg += HIG "可是$p" HIG "身子急退，躲过了$P" HIG "漫天射出的" +
		       weapon->name() + HIG "。"NOR"\n";
		message_combatd(msg, me, target);
	}

	me->reset_action();
	return 1;
}
