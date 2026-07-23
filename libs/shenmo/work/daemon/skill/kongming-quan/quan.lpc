// Code of JHSH
//  /kungfu/skill/kongming-quan/quan.c 乱拳飞舞
// sdong 07/98
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage,skill,wap,wdp;
	string *limb, type, result, str,msg;

	type = "内伤";

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("乱拳飞舞只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("空手才能施展乱拳飞舞！\n");

	if( me->query_skill_mapped("unarmed") != "kongming-quan" )
		return notify_fail("你所用的并非空明拳，不能施展乱拳飞舞！\n");
        if(me->is_busy())
        return notify_fail("你现在正忙。\n");
//	if( me->query_skill_prepared("unarmed") != "kongming-quan" )
//                return notify_fail("你所备的并非空明拳，不能施展乱拳飞舞！\n");

/*
	if( me->query_skill_mapped("force") != "xiantian-gong" )
                return notify_fail("你所用的并非先天功，施展不出乱拳飞舞！\n");
*/

        if( me->query_skill("force") < 120 )
		return notify_fail("你的先天功火候未到，无法施展乱拳飞舞！\n");

        if( me->query_skill("unarmed") < 120 )
		return notify_fail("乱拳飞舞需要精湛的空明拳方能有效施展！\n");

	if( me->query("max_neili") <= 1000 )
                return notify_fail("你的内力等级不够使用乱拳飞舞！\n");

        if( me->query("neili") <= 1000 ) 
                return notify_fail("你的内力不够，无法继续施展乱拳飞舞！\n");

	msg = HIY"$N张口一声暴喝，双目精光四射，接着身形飘忽不定，双拳幻化出漫天拳影重重向$n笼罩过去！\n\n"NOR;
	message_vision(msg, me, target);

skill =   (int)me->query_skill("kongming-quan");
if (skill>=400) skill=400;
	me->add_temp("apply/damage",  skill/3);
        me->add_temp("apply/attack", skill/3);
if (random(5)==0) target->start_busy(3);
	message("vission",HIR  "上一拳！\n" NOR,environment(me));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	message("vission",HIR  "下一拳！\n" NOR,environment(me));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	message("vission",HIR  "左一拳！\n" NOR,environment(me));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	message("vission",HIR  "右一拳！\n" NOR,environment(me));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	message("vission",HIR  "前一拳！\n" NOR,environment(me));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	message("vission",HIR  "后一拳！\n" NOR,environment(me));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	message("vission",HIR  "最后再一拳！\n" NOR,environment(me));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->start_busy(3);

        me->add_temp("apply/damage",-skill/3);
        me->add_temp("apply/attack", -skill/3);

	me->add("neili", -skill);

	return 1;
}
