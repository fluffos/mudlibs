// chan.c 云龙鞭法 缠字诀



inherit F_SSERVER;

string query_name() { return "缠字诀"; }
string *pfm_type() { return ({ "whip", }); }

int perform(object me, object target)
{
	string msg;
	object weapon;

	if (! target) target = offensive_target(me);

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    weapon->query("skill_type") != "whip")
		return notify_fail("你手里没有鞭，不能使用「缠」字诀！\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("yunlong-bian",1) < 50)
		return notify_fail("你的「云龙鞭法」功力太浅，使不了「缠」字诀！\n");

	if (me->query_skill_mapped("whip") != "yunlong-bian")
		return notify_fail("你没有激发云龙鞭法，不能使用「缠」字诀！\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功火候不够，使不了「缠」字诀！\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = CYN "$N" CYN "使出云龙鞭法「缠」字诀，连挥长鞭企图把$n"
	      CYN "的全身缠住。"NOR"\n";

	if (random(me->query_skill("whip")) > target->query_skill("parry") / 2)
	{
		msg += HIY "结果$p" HIY "被$P" HIY "攻了个措手不及！"NOR"\n";
		target->start_busy((int)me->query_skill("whip") / 22 + 1);
		me->start_busy(1 + random(2));
	} else
	{
		msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，并没有上当。"NOR"\n";
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
	return 1;
}
