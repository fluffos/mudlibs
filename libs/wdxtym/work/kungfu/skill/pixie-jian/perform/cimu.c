// cimu.c  辟邪剑法「刺目」

#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "葵花刺目"; }
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	int lvl;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「刺目」只能对战斗中的对手使用。\n");
			
	if (me->query_skill_mapped("sword") != "pixie-jian")
		return notify_fail("你没有激发辟邪剑法为剑法，难以施展「葵花刺目」。\n");
	
	weapon = me->query_temp("weapon");
	if (!weapon)
		return notify_fail("「刺目」需要手持兵器方可施展。\n");
	if (weapon && weapon->query("skill_type") != "sword" &&
	    weapon->query("skill_type") != "pin")
		return notify_fail("你不能使用这种兵器施展「群邪辟易」！\n");
	
	if (target->query_temp("block_msg/all"))
		return notify_fail("对方现在什么也看不见，你放心的继续攻击吧！\n");

	if ((int)me->query_skill("pixie-jian", 1) < 80 )
		return notify_fail("你辟邪剑法不够娴熟，使不出「刺目」。\n");

	if ((int)me->query("max_neili")<400)
		return notify_fail("你内力修为不足，无法运足内力。\n");

	if ((int)me->query("neili")<200)
		return notify_fail(HIC"你现在真气不够，没能将「刺目」使完！"NOR"\n");

	if (! living(target))
	    return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "手中" + weapon->name() +
		      HIC "一振，剑尖一点暴长，分刺$n"
		      HIC "左右双目，"NOR"\n";
	
	if (random(me->query_skill("sword")) > target->query_skill("dodge") / 2)
	{
		me->start_busy(2);
		lvl = (int)me->query_skill("pixie-jian", 1);
		damage = lvl + (int)me->query_skill("sword", 1) / 2;
		damage = damage / 2 + random(damage / 2);
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage / 2, me);
		msg += HIC "$n" HIC "只看到寒尖一点，双目一阵剧痛，眼前一"
		       "黑，就什么也看不见了，顿时长声痛极而呼！"NOR"\n";
		message_combatd(msg, me, target);
		me->add("neili", -damage / 5);
		target->set_temp("block_msg/all", 1);
		call_out("cimu_end", (int) 2 + random(lvl / 25), me, target);
	} else
	{
		me->start_busy(2);
		msg += HIY "$p" HIY "情急智生，抬手也向$P"
		       HIY "的右眼刺去，迫得$P" HIY "回剑跃开。"NOR"\n";
		message_combatd(msg, me, target);
	}
	return 1;
}

void cimu_end(object me, object target)
{
	if (target && living(target) &&
	    target->query_temp("block_msg/all"))
	{
		message_combatd("$N抹了抹流着" HIR "鲜血" NOR
				"，终于能看见了。\n", target);
		target->set_temp("block_msg/all", 0);
		tell_object(target, HIR "你终于抹掉了眼前的鲜"
			    "血，能看见了。"NOR"\n");
	}

	return;
}
