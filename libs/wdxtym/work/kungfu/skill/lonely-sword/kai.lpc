// yi.c 剑意

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "剑开"ZJBR"天门"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("你只能对战斗中的对手使用绝招。\n");
	
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("无剑如何运用剑意？\n");

	if ((int)me->query("neili") < 2400)
		return notify_fail("你现在的真气不够，无法使用剑意！\n");

	if ((int)me->query_skill("lonely-sword", 1) < 240)
		return notify_fail("你的独孤九剑还不到精通，无法使用一剑开天门！\n");

	if (me->query_skill_mapped("sword") != "lonely-sword") 
		return notify_fail("你没有激发独孤九剑，你怎么使用九剑的招数！\n");

   // if (! living(target))
	//    return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	switch (random(3))
	{
	case 0:
		msg = HIM "$N" HIM "调动全身气机，运用全身的劲力，一剑劈砍而下。"NOR"\n";
		break;

	case 1:
		msg = HIM "$N" HIM "你屏息凝神，挥出" + weapon->name() +
		       HIM "，看似平淡，却暗藏杀机。"NOR"\n";
		break;

	default:
		msg = HIM "$N" HIM "挥出一剑，剑光暴涨把$n覆盖。"NOR"\n";
		break;
	}

	ap = me->query_skill("lonely-sword", 1) + me->query_skill("martial-cognize", 1) / 2 + me->query("int")*12;
	dp = target->query_skill("parry", 1) + target->query_skill("martial-cognize", 1) / 2 + target->query("str")*15;
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap * 2 + random(ap/2)+ me->query("int")*18 ;
		me->add("neili", -2400);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80,
					   HIR "$n" HIR "全然无法抵挡$P"
					   HIR "这一剑之威！"NOR"\n");
		me->start_busy(2);
	} //else
	//if (target->query_skill("martial-cognize", 1) + target->query_skill("lonely-sword", 1) > 150)
	//{
	//	msg += CYN "然而$n" CYN "深通其中奥妙，见招拆招，让$N"
	//	       CYN "的攻击全然不能发挥作用。\n";
	//	me->add("neili", -80);
	//	me->start_busy(3);
	//}
	else
	{
		msg += CYN "$n" CYN "如临大敌，屏息凝神的面对$P"
		       CYN "的招数。才堪堪挡下，却也受了不小的内伤。"NOR"\n";
		me->add("neili", -2400);
		me->start_busy(10);
		damage = 1000;
	}
	message_combatd(msg, me, target);

	return 1;
}
