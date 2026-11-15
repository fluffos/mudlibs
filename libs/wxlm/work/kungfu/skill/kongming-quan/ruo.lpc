// ruo.c 空明若玄



inherit F_SSERVER;

string query_name() { return "空明"ZJBR"若玄"; }
string *pfm_type() { return ({ "unarmed", }); }

int perform(object me, object target)
{
	int level;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("空灵拳法「空明若玄」只能对战斗中的对手使用。\n");
	
	if (userp(me) &&me->query("family/family_name") != "古墓派"&& me->query("family/family_name") != "全真教")
		return notify_fail("空明若玄必须是全真或古墓弟子才能使用。\n");
	
	if (objectp(me->query_temp("weapon")))
		return notify_fail("你不能使用的武器。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
		
	if ((level = me->query_skill("kongming-quan", 1)) < 100)
		return notify_fail("你的空灵拳法不够娴熟，不会使用「空明若玄」。\n");

	if (me->query_skill_mapped("unarmed") != "kongming-quan")
		return notify_fail("你必须激发空灵拳法才能使用「空明若玄」。\n");

	if (me->query_skill_prepared("unarmed") != "kongming-quan")
		return notify_fail("你现在没有准备使用空灵拳，无法使用「空明若玄」！\n");

	if (me->query("neili") < 100)
		return notify_fail("你现在真气不够，无法使用「空明若玄」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N" HIW "使出「空明若玄」，双手吞吐不定，运转如意，"
	      "连绵不绝，试图扰乱$n" HIW "的攻势。"NOR"\n";

	me->add("neili", -50);
	if (random(level) > (int)target->query_skill("parry", 1) / 2)
	{
		msg += HIR "结果$p" HIR "被$P" HIR "闹个手忙脚乱，"
		       "，招架不迭，全然无法反击！"NOR"\n";
		target->start_busy(level / 50 + 2);
	} else
	{
		msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，镇"
		       "定逾恒，全神应对自如。"NOR"\n";
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
