// feilong.c 华山剑法「天外飞龙」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon;
        int damage;

        if( !target ) target = offensive_target(me);

	if( !me->query("feilong"))
		return notify_fail("你的外功中没有这项技能。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你必须使剑才能使用「天外飞龙」！\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「天外飞龙」只能对战斗中的对手使用。\n");


        if( (int)me->query_skill("huashan-jianfa", 1) < 100 )
	        return notify_fail("你的华山剑法不够娴熟，不会使用「天外飞龙」。\n");

        if( (int)me->query_skill("huashan-neigong",1) < 100 )
                return notify_fail("你的华山内功等级不够，无法使用「天外飞龙」这招。\n");

        msg = CYN "$N使出华山剑法绝招「天外飞龙」，纵身一跃，身子在空中一扭，耍了一个剑花，趁$n一愣，一剑刺向$n前胸。\n";

        me->start_busy(1);
  	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") * 2 / 5)
	{
                msg += "结果$p被$P一剑刺中要害，无法支撑，倒在地上。\n" NOR;
	        message_vision(msg, me, target);
		damage = (int)me->query_skill("huashan-jianfa", 1);
	        damage = damage * 5 / 2 ;
                target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage / 2, me);
        }
	else
	{
                msg += "可是$p早有防备，轻松得躲开了。\n" NOR;
	        message_vision(msg, me, target);
		me->start_busy(3);
        }
	me->add("neili", - 200);
        return 1;
}
