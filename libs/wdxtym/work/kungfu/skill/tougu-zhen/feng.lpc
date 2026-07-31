#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "透骨"ZJBR"封杀"; }
string *pfm_type() { return ({ "finger", }); }

int perform(object me, object target)
{
	string msg;
	int ap, dp;
	int damage;
	int lvl;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("透骨针「封杀」只能在战斗中使用。\n");

	if ((int)me->query_skill("tougu-zhen", 1) < 100)
		return notify_fail("你的透骨针还不够娴熟，无法施展「封杀」绝技！\n");

	if ((int)me->query_skill("force") < 160)
		return notify_fail("你内功火候不够，难以施展「封杀」绝技！\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的真气不够，无法施展「封杀」绝技！！\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你的真气不够，无法施展「封杀」绝技！！\n");

	if (me->query_skill_mapped("finger") != "tougu-zhen") 
		return notify_fail("你没有激发透骨针，无法使用「封杀」绝技！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N使出透骨针「封杀」绝技，手指挥舞，幻出漫天寒星，携带着阴寒之劲直封$n各处要穴！"NOR"\n";

	lvl = me->query_skill("tougu-zhen", 1);
	ap = me->query_skill("finger") + me->query_skill("force");
	dp = target->query_skill("parry") + me->query_skill("dodge");
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap / 3 + random(ap / 4);
		target->affect_by("tougu_zhen",
			       ([ "level" : me->query("jiali") + random(me->query("jiali")),
				  "id"    : me->query("id"),
				  "duration" : lvl / 50 + random(lvl / 20) ]));
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
	      HIR "结果只听$n一声惨嚎，被攻个正着，透骨针极寒之劲攻心，全身瘫麻，鲜血狂喷！"NOR"\n");

		me->add("neili", -250);
		me->start_busy(1);
	} else
	{
		msg += CYN "可是$n急忙退闪，连消带打躲开了这一击。"NOR"\n";
		me->start_busy(3);
		me->add("neili", -50);
	}
	message_combatd(msg, me, target);

	return 1;
}

