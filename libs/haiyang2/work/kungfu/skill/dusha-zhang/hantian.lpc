// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	int damage;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［九重寒天掌］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = (int)me->query_skill("dusha-zhang",1) / 10;

    if ( extra < 10) return notify_fail("你的这门武功还不够纯熟！\n");
    if( (int)me->query("neili") < 600 )
    return notify_fail("你的内力不够。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "只能空手施展。\n");
                
        damage=random(extra)+50;
        extra=extra/2;
        if (extra> 200) extra=200;

        message_vision(
                HIB "\n$N气运丹田，将体内的毒素运到口中，猛的向$n喷去！\n" NOR, me, target);
        
        if( random(target->query("combat_exp")) < (int)me->query("combat_exp") / 2 ) {
        target->receive_wound("jing", damage);
                target->start_busy(5);
        message_vision("$N被$n的毒气喷中，不觉得一阵眩晕，险些倒下。\n", target, me);
                me->start_busy(3);
                
        }
else
	{
                message_vision("$N见势不妙，侧向跳开避开了$n喷的毒气。\n", target, me);
	
	}
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
        
	msg = HIR  "$N使出［九重寒天掌］，全身飞速旋转，双掌一前一后，闪电般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR  "$N使出前一掌，闪电般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR  "$N身形一换，使出后一掌，闪电般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->add("neili",-100);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
