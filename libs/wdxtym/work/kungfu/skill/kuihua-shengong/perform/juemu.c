// juemu.c  葵花神功「钟馗抉目」

#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "钟馗抉目"; }
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	int lvl;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「钟馗抉目」只能对战斗中的对手使用。\n");
	
	if (userp(me)) {
		if (! me->query("can_perform/kuihua-shengong/juemu"))
			return notify_fail("你还没有通晓天人化生的奥秘。\n");
		
		if (!me->query("special_skill/ghost"))
			return notify_fail("你没有鬼脉属性，无法运用「钟馗抉目」。\n");
		
		if ((int)me->query_skill("kuihua-shengong", 1) < 150 )
			return notify_fail("你葵花神功不够娴熟，使不出「钟馗抉目」。\n");
		
		if (me->query_skill_mapped("sword") != "kuihua-shengong")
			return notify_fail("你没有激发葵花神功为剑法，难以施展「钟馗抉目」。\n");
	}
	
	weapon = me->query_temp("weapon");
	if (!weapon)
		return notify_fail("「钟馗抉目」需要手持兵器方可施展。\n");
	if (weapon &&
	    weapon->query("skill_type") != "pin")
		return notify_fail("你必须使用“针”这种兵器施展「群邪辟易」！\n");
	
	if (target->query_temp("block_msg/all"))
		return notify_fail("对方现在什么也看不见，你放心的继续攻击吧！\n");

	if ((int)me->query("max_neili")<400)
		return notify_fail("你内力修为不足，无法运足内力。\n");

	if ((int)me->query("neili")<200)
		return notify_fail(HIC"你现在真气不够，没能将「钟馗抉目」使完！"NOR"\n");

	if (! living(target))
	    return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "手中" + weapon->name() +
		      HIC "一振，剑尖一点暴长，分刺$n"
		      HIC "左右双目，"NOR"\n";
	
	if (random(me->query_skill("sword")*120/100) > target->query_skill("dodge") / 2)
	{
		me->start_busy(2);
		lvl = (int)me->query_skill("kuihua-shengong", 1);
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
