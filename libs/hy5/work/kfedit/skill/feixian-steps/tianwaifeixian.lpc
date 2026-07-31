// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("天外飞仙只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	if (!weapon) return notify_fail("天外飞仙只能和飞仙剑法配和！\n");
	if( (string)weapon->query("skill_type") != "sword" )
	return notify_fail("天外飞仙只能和飞仙剑法配和！\n");
	if ( (string) me->query_skill_mapped("sword") != "feixian-sword")
	return notify_fail("天外飞仙只能和飞仙剑法配和！\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-200);

	extra = me->query_skill("feixian-sword",1) / 20;
	extra += me->query_skill("feixian-steps",1) /20;

	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = RED  "$N脚踏［飞仙步法］，同时使出［飞仙剑法中］的精髓－－天外飞仙，手中的"+ weapon->name() +"划出一道长虹，闪电般的击向$n！" NOR;

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "剑光一闪，消失．．．．\n" NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
	msg = RED "$N身形突转，御剑回飞！\n" NOR;

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
