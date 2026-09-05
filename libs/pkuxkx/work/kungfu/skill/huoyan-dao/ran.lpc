// by darken@SJ

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;

}
int perform(object me, object target)
{
	string msg;
	int hs, ls, ret;
#define LEVEL 3000

	hs = me->query_skill("huoyan-dao",1);
	ls = me->query_skill("longxiang-boruo",1);

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
            return notify_fail("「燃」只能对战斗中的对手使用。\n");

	if ( me->check_hand() > 0 )
		return notify_fail("你只能双手空手运用「燃」的绝技。\n");

	if( hs < 60)
		return notify_fail("你的「火焰刀」等级不够, 不能使出「燃」的绝技！\n");

	if( ls < 60)
		return notify_fail("你的「龙象般若功」功力不够, 不能使出「燃」的绝技！\n");

	if( me->query("neili") < 10000 )
		return notify_fail("你的内力即将用尽，发不出「燃」了！\n");

	if( me->query("jingli") < 3000 )
		return notify_fail("你的精力即将用尽，发不出「燃」了！\n");

	if( me->query("max_neili") < 5000 )
		return notify_fail("你的内力不够，不能催动内力发出「燃」绝技！\n");

/*	if( me->query_skill_mapped("strike") != "huoyan-dao"
	 || me->query_skill_prepared("strike") != "huoyan-dao")
		return notify_fail("你必须使用「火焰刀」，才能使出「燃」的绝技！\n"); */

	if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        me->query_skill_mapped("force") != "longxiang-boruo")
		return notify_fail("你现在所使用的内功同「龙象般若功」相抵触，不能使出「燃」的绝技！\n");

	if ( time()-me->query("kungfu/ran")<300 )
		return notify_fail("你刚使用过「燃」，等气息平复以后再说吧。\n");

	msg = HIR "\n$N双掌一聚气，挟著一股热气向$n击出！\n"NOR;
	ret=ls+hs;
	if ( ret>=3000 )
		ret=2999;
//命中率C+	
	if( F_KUNGFU->hit_rate( me->query_skill("force", "longxiang-boruo"), target->query_skill("force"), 7, me, target) )
	{
		msg+= HIR "$n只觉得全身燥热，内息乱冲！\n"NOR;
		F_KUNGFU->hit_wound("qi", target->query("qi")*ret/LEVEL, target->query("eff_qi")*ret/LEVEL, me, target);
		target->set("neili", target->query("neili")*(LEVEL-ret)/LEVEL);
		me->start_busy(2);
		me->add("neili",-4000);
		me->set("kungfu/ran",time());
        message_vision(msg, me, target);
        COMBAT_D->report_status(target); 
	}
	else
	{
		msg += HIY "可是$n看破了$N的企图，当即运起全身内力将这股热气反震了回去。\n" NOR;
		msg+= HIR "$N只觉得全身燥热，内息乱冲！\n"NOR;
		F_KUNGFU->hit_wound("qi", me->query("qi")*ret/LEVEL, me->query("eff_qi")*ret/LEVEL, target, me);
		me->add("neili",-4000);
		target->add("neili",-800);
        message_vision(msg, me, target);
        COMBAT_D->report_status(me); 
		if ( !target->is_busy() ) target->start_busy(2);
	}
	me->start_perform(5, "燃字诀");
	return 1;
}
