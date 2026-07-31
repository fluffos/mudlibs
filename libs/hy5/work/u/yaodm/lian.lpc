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
                return notify_fail("瀑布剑法的波涛汹涌只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("你的内力不够。\n");
        if( (int)me->query_skill("xuantie-jianfa", 1) < 50 )
                return notify_fail("你的瀑布剑法不够娴熟，不能用波涛汹涌。\n");

        extra = me->query_skill("xuantie-jianfa",1) / 10;

	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
        msg = HIR  "$N使出［瀑布剑法中］的波涛汹涌，手中的"+ weapon->name() +" 一招连着一招闪电般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "一个巨浪打来，消失．．．．\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/3;i++)
	{
        msg = HIY "$N又推出了一个巨浪，卷了上来！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("neili", - 60 * i);
	me->start_busy(3);
	return 1;
}

