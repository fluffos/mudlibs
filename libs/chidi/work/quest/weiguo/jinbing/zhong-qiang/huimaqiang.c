// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
        if( (int)me->query_skill("zhong-qiang",1) < 50)
        return notify_fail("你目前功力还使不出「雷霆霹雳」。\n");
    	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "club")
			return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 100 )
    return notify_fail("你的内力不够。\n");
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［雷霆霹雳］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("wind-blade",1) / 10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIC  "$N一回身手中的"+ weapon->name() +"突然刺出，"+weapon->name() +"划破空气，无可低档般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
