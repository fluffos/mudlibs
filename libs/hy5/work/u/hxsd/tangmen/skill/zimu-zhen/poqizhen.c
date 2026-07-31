// poqizhen.c 破气针
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("zimu-zhen",1);

	if( !(me->is_fighting() ))
		return notify_fail("「破气针」只能在战斗中用在对手身上。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("biyun-xinfa", 1) < 100 )
                return notify_fail("你的碧云心法不够高。\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力太弱。\n");


	if( skill < 80)
		return notify_fail("你的子母针法不够纯熟, 不能使用「破气针」！\n");

	if( me->query("neili") < 150 )
		return notify_fail("你的内力不够，无法运用「破气针」！\n");
 
	msg = HIY "$N并指入刀，指缝间夹着三枚暗器,潜运内力，一式「破气针」，直奔$n的上、中、下丹田打去。\n";
	message_vision(msg, me, target);
 
	ap = me->query_skill("throwing") + skill;
	dp = target->query_skill("force") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-100);
		msg = "$N「破气针」正中目标, $n顿时觉得丹田上一阵刺痛，\n";
		msg += "全身真气狂泄而出！\n" NOR;

		neili_wound = 500 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = neili_wound / 5;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");

		target->add("neili", -neili_wound);
		target->add("qi", -qi_wound);
		target->add("eff_qi", -qi_wound);
		target->start_busy(2);
        target->apply_condition("tmpili_poison", 10);

//		me->start_busy(random(2));
	}
	else
	{
		if(userp(me))
			me->add("neili",-80);
		msg = "可是$n瞬间反应过来，腾挪跳跃，躲过了这次重创。\n"NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);

	return 1;
}
