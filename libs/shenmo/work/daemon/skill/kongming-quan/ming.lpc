// Code of JHSH
//  /kungfu/skill/kongming-quan/kongming.c 灵台空明
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
		return notify_fail("灵台空明只能对战斗中的对手使用。\n");

	if( me->query_temp("sanhua") )
		return notify_fail("你已在使用三花聚顶了！\n");

	if( me->query_temp("kongming") )
		return notify_fail("你已在使用灵台空明了！\n");
        if(me->is_busy())
        return notify_fail("你现在正忙。\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("空手才能施展灵台空明！\n");

	if( me->query_skill_mapped("unarmed") != "kongming-quan" )
		return notify_fail("你所用的并非空明拳，不能施展灵台空明！\n");

//	if( me->query_skill_prepared("unarmed") != "kongming-quan" )
//                return notify_fail("你所备的并非空明拳，不能施展灵台空明！\n");

/*
	if( me->query_skill_mapped("force") != "xiantian-gong" )
                return notify_fail("你所用的并非先天功，施展不出灵台空明！\n");
*/

        if( me->query_skill("force") < 100 )
		return notify_fail("你的先天功火候未到，无法施展灵台空明！\n");

        if( me->query_skill("unarmed") < 100 )
		return notify_fail("灵台空明需要精湛的空明拳方能有效施展！\n");

	if( me->query("neili") <= 300 )
		return notify_fail("你的内力不够使用灵台空明！\n");

	if( me->query("jing") <= 200 )
		return notify_fail("你的精不够使用灵台空明！\n");


	msg = HIY"$N深吸一口气，目光猛然清澈无比，接着双拳十字交错，缓缓向$n推了过去！\n\n"NOR;
	message_vision(msg, me, target);

	me->set_temp("kongming", 1);

	skill =   (int)me->query_skill("kongming-quan");
if (skill>=400) skill=400;
	me->add_temp("apply/attack", skill/2);
	me->add_temp("apply/damage",  skill/6);
	me->add_temp("apply/dodge",  skill/2);
	me->add_temp("apply/parry",  skill/2);
	me->add_temp("apply/defense",  skill/2);
if (random(2)==0) target->start_busy(3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->add("neili", -skill/2);

	me->add("jing", -100);
	me->start_busy(random(2));

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill/10);

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/damage", -amount/3);
	me->add_temp("apply/parry", -amount);
	me->add_temp("apply/dodge", -amount);
	me->add_temp("apply/defense", -amount);
	me->delete_temp("kongming");
	message_vision(HIY "\n$N吸了一口气，将内力收回丹田！\n\n" NOR, me);

	return;
}
