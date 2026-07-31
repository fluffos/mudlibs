// 弹射火焰

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "弹射"ZJBR"火焰"; }

int perform(object me, object target)
{
	object du;
	int damage;
	int ap;
	string msg;
	int lvl;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("你只能对战斗中的对手弹射火焰。\n");

	if ((int)me->query_skill("chousui-zhang", 1) < 80)
		return notify_fail("你的抽髓掌火候不够。\n");

	if ((int)me->query_skill("poison", 1) < 80)
		return notify_fail("你的基本毒技火候不够。\n");

	if ((int)me->query_skill("huagong-dafa", 1) < 80)
		return notify_fail("你的化功大法火候不够。\n");

	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力修为不足，无法用内力弹射出火焰。\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("你现在内息不足，无法用内力弹射出火焰。\n");

	if (! objectp(du = me->query_temp("handing")) && userp(me))
		return notify_fail("你首先要拿着(hand)一些毒药作为引子。\n");

	if (objectp(du) && ! mapp(du->query("poison")))
		return notify_fail(du->name() + "又不是毒药，怎么弹射？\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "诡异的一笑，暗自提运内力，手指对准$n"
	      HIR "轻轻一弹，只见一点殷红色的火星向$n" HIR "飘去。"NOR"\n";
	me->start_busy(2);
	me->add("neili", -120);

	lvl = me->query_skill("chousui-zhang", 1);
	damage = 50 + random(lvl) / 2;

	if (me->query("max_neili") + random(me->query("max_neili")) <
	    target->query("max_neili") * 15 / 10)
	{
		msg += WHT "可是$n" WHT "浑然不放在眼里，衣袖轻轻一拂，便将火星熄灭。"NOR"\n";
	} else
	{
		ap = me->query_skill("poison", 1) / 2 +
		     me->query_skill("force");
		if (ap + random(ap) < target->query_skill("dodge"))
		{
			msg += CYN "$n" CYN "见势不妙，急忙腾"
			       "挪身形，避开了$N" CYN "的攻击。"NOR"\n";
		} else
		{
			msg += HIG "$n" HIG "只觉得伤口一阵灼伤，随即便跟着麻木起来。"NOR"\n";
			target->affect_by("fire_poison",
				       ([ "level" : me->query("jiali") + random(me->query("jiali")),
					  "id"    : me->query("id"),
					  "duration" : lvl / 50 + random(lvl / 20) ]));
			target->receive_damage("qi", damage, me);
			target->receive_damage("jing", damage / 2, me);
		}
	}

	if (objectp(du)) destruct(du);
	message_combatd(msg, me, target);

	return 1;
}
