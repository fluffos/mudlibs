// 弹射碧焰

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "弹射"ZJBR"碧焰"; }

int perform(object me, object target)
{
	object du;
	int damage;
	int ap;
	string msg;
	int lvl;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("你只能对战斗中的对手弹射碧焰。\n");

	if ((int)me->query_skill("chousui-zhang", 1) < 150)
		return notify_fail("你的抽髓掌火候不够。\n");

	if ((int)me->query_skill("poison", 1) < 180)
		return notify_fail("你的基本毒技火候不够。\n");

	if ((int)me->query_skill("huagong-dafa", 1) < 150)
		return notify_fail("你的化功大法火候不够。\n");

	if ((int)me->query("max_neili") < 1500)
		return notify_fail("你的内力修为不足，无法用内力弹射碧焰。\n");

	if ((int)me->query("neili") < 800)
		return notify_fail("你现在内息不足，无法用内力弹射碧焰。\n");

	if (! objectp(du = me->query_temp("handing")) && userp(me))
		return notify_fail("你首先要拿着(hand)一些毒药作为引子。\n");

	if (objectp(du) && ! mapp(du->query("poison")))
		return notify_fail(du->name() + "又不是毒药，无法弹射？\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "红着双眼，猛提内力，对准$n"
	      HIR "“嗖”的一声，弹射出一点绿莹莹明亮无比的" NOR +
	      HIG "碧焰" NOR + HIR "悄然袭去。"NOR"\n";
	me->start_busy(2);
	me->add("neili", -300);

	lvl = me->query_skill("chousui-zhang", 1);
	damage = 100 + random(lvl);

	if (me->query("max_neili") + random(me->query("max_neili")) < target->query("max_neili") * 17 / 10)
	{
		msg += WHT "可是$n" WHT "浑然不放在眼里，衣袖轻轻一拂，便将" NOR +
		       HIG "碧焰" NOR + WHT "熄灭。"NOR"\n";
	} else
	{
		ap = me->query_skill("poison", 1) / 2 +  me->query_skill("force");
		if (ap + random(ap) < target->query_skill("dodge"))
		{
			msg += CYN "$n" CYN "见势不妙，急忙腾挪身形，避开了$N" CYN "的攻击。"NOR"\n";
		} else
		{
			msg += HIR "结果$n" HIR "一个不慎，被火星溅到了衣衫，哪知" NOR +
			       HIG "碧焰" HIR "一接触身体便开始\n大肆燃烧，只听得$p"
			       HIR "惨叫连连。"NOR"\n";
			target->affect_by("fire_poison",
				       ([ "level" : me->query("jiali") + random(me->query("jiali") * 2),
					  "id"    : me->query("id"),
					  "duration" : lvl / 25 + random(lvl / 15) ]));
			target->receive_damage("qi", damage, me);
			target->receive_damage("jing", damage / 2, me);
		}
	}

	if (objectp(du)) destruct(du);
	message_combatd(msg, me, target);

	return 1;
}
