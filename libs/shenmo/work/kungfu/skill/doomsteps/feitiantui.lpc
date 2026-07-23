// tie@fengyun

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
		return notify_fail("［飞天腿］只能对战斗中的对手使用。\n");
		if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("只能空手使用。\n");		

        me->add("neili",-100);

	weapon = me->query_temp("weapon");
	extra = me->query_skill("doomsteps",1) / 10;
	me->add_temp("apply/attack", extra);	
	msg = HIR  "$N猛一个翻身，迅捷无比地向$n踢出飞天一腿！" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
	me->add_temp("apply/attack", -extra);
	me->start_busy(1);
	return 1;
}
