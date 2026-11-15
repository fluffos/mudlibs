// shang.c 「伤神剑」



inherit F_SSERVER;

string query_name() { return "伤神剑"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;

	if (userp(me) && ! me->query("can_perform/damo-jian/shang"))
		return notify_fail("你不会使用「伤神剑」。\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「伤神剑」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("damo-jian", 1) < 200)
		return notify_fail("你的达摩剑法不够娴熟，不会使用「伤神剑」。\n");

	if (me->query("neili") < 300)
		return notify_fail("你现在真气不够，无法使用「伤神剑」。\n");

	if (me->query_skill_mapped("sword") != "damo-jian")
		return notify_fail("你没有激发达摩剑法，无法使用「伤神剑」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIM "$N" HIM "将" + weapon->name() + "轻轻一振，剑脊叮叮作响，无形"
	      "剑气直指$n" HIM "的气海穴！"NOR"\n";

	me->add("neili", -200);
	ap = me->query_skill("sword") + me->query_skill("force");
	dp = target->query_skill("force") * 2;

	if (ap / 3 + random(ap) > dp)
	{
		msg += HIR "结果$p" HIR "觉得气海穴上一痛，眼前"
		       "一团黑，阵阵晕眩，难以继续战斗！"NOR"\n";
		damage = ap / 40 + random(ap / 40);
		target->receive_damage("jing", damage, me);
		target->receive_wound("jing", damage / 2, me);
		target->affect_by("damo_shangshen",
			       ([ "level" : ap / 4 + random(ap / 4),
				  "id"    : me->query("id"),
				  "duration" : ap / 90 + random(ap / 90) ]));
		me->start_busy(2);
	} else
	{
		msg += CYN "可是$p" CYN "内力深厚，使得$P" CYN
		       "这一招没有起到任何作用。"NOR"\n";
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
