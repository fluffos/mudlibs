
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "绝户手"; }

int perform(object me, object target)
{
	int damage;
	string msg;

	if (! target) target = offensive_target(me);

	if (userp(me) && ! me->query("can_perform/huzhua-shou/juehu"))
		return notify_fail("你现在还不会使用「绝户」这一招！\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail("「绝户」只能对战斗中的对手使用。\n");

	if (me->query("shen") < 10000)
		return notify_fail("你恶念顿生，刚想对对手施展绝户，可突然想到了当初鱼莲舟的一番告诫，不得不中途放弃了攻击。\n");

	if ((int)me->query_skill("huzhua-shou", 1) < 120)
		return notify_fail("你的虎爪绝嗣手不够娴熟，不会使用「绝户」。\n");

	if (me->query("neili") < 300)
		return notify_fail("你现在真气不够，不能使用「绝户」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "大喝一声，变掌为爪，双爪化出漫天爪影，如狂风骤雨一般向$n" HIR
	      "的要害抓去！"NOR"\n";

	if (random(me->query_skill("claw")) > target->query_skill("parry") / 2)
	{
		me->start_busy(3);

		damage = me->query_skill("huzhua-shou", 1);
		damage = damage * 4 + random(damage * 10);
		me->add("shen", -8000);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 25,
					   HIR "结果$p" HIR "一声惨嚎，没能招架住$P" HIR
					   "凌厉的攻势，被抓得皮肉分离，鲜血飞溅！"NOR"\n");
		me->add("neili", -200);
	} else
	{
		me->start_busy(2);
		me->add("neili", -120);
		me->add("shen", -8000);
		msg += CYN "可是$p" CYN "看破了$N" CYN
		       "的企图，躲开了这招杀着。"NOR"\n";
	}
	message_combatd(msg, me, target);

	return 1;
}

