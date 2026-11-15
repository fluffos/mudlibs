// muyeyingyang.c 牧野鹰扬



inherit F_SSERVER;

string query_name() { return "牧野"ZJBR"鹰扬"; }

int perform(object me, object target)
{
      int num;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("牧野鹰扬只能对战斗中的对手使用。\n");

	if ((int)me->query_str() < 30)
		return notify_fail("你臂力不够,不能使用牧野鹰扬！\n");

	if ((int)me->query_skill("sougu",1) < 150)
		return notify_fail("你的搜骨鹰爪功修为不够,目前还不能使用牧野鹰扬！\n");

	if ((int)me->query("neili") < 800)
		return notify_fail("你内力现在不够, 不能使用牧野鹰扬！\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "使出搜骨鹰爪功绝技「牧野鹰扬」，双爪蓦地抓向$n"
	      HIY "的全身要穴。"NOR"\n";

	if (random(me->query("combat_exp"))/10000 * me->query_skill("sougu", 1) > (int)target->query("combat_exp") / 20000 * target->query_skill("dodge", 1) )
	{
		msg += HIR "结果$p" HIR "被$P" HIR "抓住要穴，立时动弹不得！"NOR"\n";
            num = me->query_skill("sougu", 1) / 30;
            if (num>10) num=10;
		target->start_busy( num );
		me->add("neili", -150);
	} else
	{
		msg += HIG "可是$p" HIG "看破了$P" HIG "的企图，并没有上当。"NOR"\n";
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
