// ci.c canhe-zhi perform 刺字诀
// by leontt 1/5/2000
// modified by darken to reduce busy time

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int improve);

int perform(object me, object target)
{
	string msg;
	int improve, ap, dp, skill, i;

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !me->is_fighting(target) )
		return notify_fail("「刺字诀」只能在战斗中对对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手使用「刺字诀」！\n");

	if( (int)me->query_skill("canhe-zhi",1) < 100 )
		return notify_fail("你的参合指不够娴熟，不会使用「刺字诀」！\n");

	if( (int)me->query_skill("shenyuan-gong",1) < 100 )
		return notify_fail("你的神元功等级不够，不能使用「刺字诀」！\n");

	if( (int)me->query_str(1) < 30 )
		return notify_fail("你的臂力不够强，不能使用「刺字诀」！\n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("你的内力太弱，不能使用「刺字诀」！\n");

	if( (int)me->query("neili") < 600 )
		return notify_fail("你的内力太少了，无法使用出「刺字诀」！\n");

	if (me->query_skill_prepared("finger") != "canhe-zhi"
	|| me->query_skill_mapped("finger") != "canhe-zhi")
		return notify_fail("你现在无法使用「刺字诀」进行攻击。\n");

        if ( me->query_skill_mapped("force") != "shenyuan-gong")
           return notify_fail("没有神元功支持如何使用「刺字诀」！\n");
	if ( me->query_skill_mapped("parry") != "canhe-zhi"
	&& me->query_skill_mapped("parry") != "douzhuan-xingyi")
		return notify_fail("你现在无法使用「刺字诀」进行攻击。\n");

//	if( target->query_temp("ci"))
//		return notify_fail("你正在使用参合指的特殊攻击「刺字诀」！\n");

	msg = HIC"\n$N突然一掌拍在自己的丹田上激荡全身的内力形成一股「"HIR"剑气"HIC"」，从右手拇指激射而出，刺向$n的肩部。\n" NOR;
	message_vision(msg, me, target);

//	pfm ci 中不出 aut pfm 的标记 by lane
	me->set_temp("mr_ci", 1);


	ap = COMBAT_D->skill_power(me, "finger", SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

	if ( target->is_busy())
		dp -= dp/3;

	skill = me->query_skill("canhe-zhi", 1);

	i = skill/3;
	if ( skill > 250 )
		i = to_int( skill/2.8 * skill/250.0);

	me->add_temp("apply/attack", i);
	me->add_temp("apply/finger", i);

	if(random(ap + dp) > dp && !target->query_temp("ci")) {
		msg = HIR"$n的肩关节一酸，双臂立时失去知觉，动弹不得。\n"NOR;
		message_vision(msg, me, target);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(3)?1:3);
		if ( skill > 150)
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
		improve = me->query("str");
		target->add_temp("apply/strength", -improve);
		target->set_temp("ci", improve);
		target->add_condition("no_perform", 2);
		target->add_busy(random(2)+1);
		me->add("neili", -100);
		me->add("jingli", -50);
		call_out("check_fight", 1, me, target ,improve, me->query_skill("finger")/30+5);
	}
	else {
		msg = CYN"$n纵身一跃，敏捷地躲过了$N的这一招，$P趁$p躲闪之际，顺势速攻几招！\n"NOR;
		message_vision(msg, me, target);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(3)?1:3);
		if ( skill > 150)
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
	}
	me->add_temp("apply/attack", -i);
	me->add_temp("apply/finger", -i);
	me->start_busy(random(2));
	me->add("neili", -250);
	me->add("jingli", -80);

	me->delete_temp("mr_ci");

	me->start_perform(2, "「刺字诀」");
	return 1;
}

void remove_effect(object target, int improve)
{
	if(!target) return;
	target->add_temp("apply/strength", improve);
	target->delete_temp("ci");
	tell_object(target, HIR"\n你运气一周脸色好了许多，只觉得双臂已经恢复了原状。\n"NOR);
}

void check_fight(object me, object target, int improve, int count)
{
	if(! target) return;
	if(! me
	|| ! me->is_fighting(target)
	|| me->query_skill_mapped("finger") != "canhe-zhi"
	|| me->query_skill_prepared("finger") != "canhe-zhi"
	|| me->query_temp("weapon")
	|| count < 0 ){
		remove_effect(target , improve);
		return;
	}
	call_out("check_fight", 1, me, target, improve, count -1);
}

string perform_name(){ return HIC"刺字诀"NOR; }

int help(object me)
{
        write(HIC"\n参合指之「刺字诀」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 600 以上；
                最大内力 1000 以上；
                参合指等级 100 以上；
                神元功等级 100 以上；
                激发指法为参合指；
                备指法为参合指；
                且手无兵器。

HELP
        );
        return 1;
}
                                
