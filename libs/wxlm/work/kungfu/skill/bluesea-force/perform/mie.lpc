// mie.c 五阴焚灭



inherit F_SSERVER;
 
string query_name() { return "五阴"ZJBR"焚灭"; }

int perform(object me, object target)
{
	string msg;
	int ap, dp;
 
	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("五阴焚灭只能在战斗中对对手使用。\n");

	if (me->query_skill("bluesea-force", 1) < 150)
		return notify_fail("你的南海玄功还不够娴熟，不能使用五阴焚灭！\n");

	if (me->query("neili") < 300)
		return notify_fail("你的真气不够！\n");

	if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "暴喝一声，变掌为爪，迅捷无比的袭向$n！\n";

	ap = me->query_skill("bluesea-force");
	dp = target->query("combat_exp") / 10000;
	me->add("neili", -60);

	me->want_kill(target);
	if (dp >= 100)
	{
		msg += HIC "$n" HIC "知道来招不善，小心应对，没出一点差错。"NOR"\n";
	} else
	if (random(ap) > dp)
	{
		msg += HIR "这一招完全超出了$n" HIR "的想象，被$N"
		       HIR "结结实实的抓中了气海穴，浑身真气登时涣散！"NOR"\n";
		message_combatd(msg, me, target);
		target->die(me);
		return 1;
	} else
	{
		msg += HIM "$n" HIM "大吃一惊，连忙胡乱抵挡，居"
		      "然没有一点伤害，侥幸得脱！"NOR"\n";
	}
	me->start_busy(2);
	message_combatd(msg, me, target);

	return 1;
}
