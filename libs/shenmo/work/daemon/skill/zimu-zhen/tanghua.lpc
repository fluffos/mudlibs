#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[唐花]只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("你的碧云心法不够高，不能运用「雨激梅花半瓣香」。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力太弱，不能使用「雨激梅花半瓣香」。\n");

extra = me->query_skill("zimu-zhen",1) / 3;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra*5);
msg = RED "$N左手一扬，唐门独门暗器----一朵令人闻风丧胆的唐花朝$n发了出去。\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIG "唐>---->\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIC "花>------->\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
        target->apply_condition("tmqidu_poison", 60);
	} 
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra*5);
        me->add("neili",-50);
	me->start_busy(2);
	target->apply_condition("zimu-zhen",random(10)+60);

return 1;
}

