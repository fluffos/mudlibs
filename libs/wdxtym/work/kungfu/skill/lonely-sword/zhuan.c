// yi.c 剑转风云

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "剑转"ZJBR"风云"; }

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
		return notify_fail("无剑如何运用剑转风云？\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你现在的真气不够，无法使用剑转风云！\n");

	if ((int)me->query_skill("lonely-sword", 1) < 320)
		return notify_fail("你的独孤九剑还不到家，无法使用剑转风云！\n");
		
	//		if ((int)me->query_skill("martial-cognize", 1) < 220)
		//return notify_fail("你的武学修养还不到220级，无法使用剑转风云！\n");

	if (me->query_skill_mapped("sword") != "lonely-sword") 
		return notify_fail("你没有激发独孤九剑，无法使用剑转风云！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	switch (random(3))
	{
	case 0:
		msg = HIM "$N" HIM "目光一凝，化破气式，剑意精妙之处融为一剑，刺向$n。"NOR"\n";
		break;

	case 1:
		msg = HIM "$N" HIM "手中" + weapon->name() +
		       HBRED"伴随$N狂舞，化作无数残影，形成气柱，涌向$n！！！"NOR"\n";
		break;

	default:
		msg = HIM "$N" HIR "举起手中的剑，在空中画了两个圈，圈内生出无数剑气，齐齐奔向$n"NOR"\n";
		break;
	}

	ap = me->query_skill("lonely-sword", 1) + me->query_skill("martial-cognize", 1) ;
	dp = target->query_skill("parry", 1) + target->query_skill("martial-cognize", 1) +
	     target->query_skill("lonely-sword", 1);
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap * 4 + random(ap);
		me->add("neili", -400);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
					   HIR "$n" HIR "已觉躲不开$P"
					   HIR "这等含巨大威力的招数，只能硬抗！"NOR"\n");
		me->start_busy(5);
	} else
	if (target->query_skill("martial-cognize", 1) + target->query_skill("lonely-sword", 1) > 350)
	{
		msg += CYN "然而$n" CYN "身法精妙，对招架兵器颇有研究$N"
		       CYN "的攻击碰不到$n的衣角。\n";
		me->add("neili", -400);
		me->start_busy(2);
	} else
	{
		msg += CYN "$n" CYN "$N并不将$P"
		       CYN "的招式放在眼里，随意招架，将$n的攻击齐齐卸开。。"NOR"\n";
		me->add("neili", -400);
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
