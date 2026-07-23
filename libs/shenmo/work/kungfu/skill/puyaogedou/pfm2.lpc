// 尾巴摇摇

#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
		object weapon;
	
extra = me->query_skill("puyaogedou");
	if( (int)me->query_skill("puyaogedou", 1) < 40 )
		return notify_fail("你不会使用加防卫力。\n");

if(me->is_busy())
		return notify_fail("你现太忙，用不出绝技！！\n");
        if( me->query("up1") < 1 )
                return notify_fail("你现在不能使用此pfm.\n");
        if( me->query("pfm2") < 1 )
                return notify_fail("你现在不能使用此pfm.\n");
		

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［尾巴摇摇］只能对战斗中的对手使用。\n");
	
me->add_temp("apply/attack",extra);
me->add_temp("apply/damage",extra*2);

	
weapon = me->query_temp("weapon");
	
msg = HIY  "$N使出龙族必杀绝技［扑咬剪］,一下子暴努起来！\n" NOR;
	message_vision(msg,me,target);
	msg = HIC  "一扑" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "二咬！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "三剪！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if (me->query("up1")==2)
{
	msg = HIC  "再扑" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "再咬！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "最后一剪！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->apply_condition("ill_dongshang",30 );
target->apply_condition("ill_fashao",30 );
target->apply_condition("ill_kesou",30 );
target->apply_condition("ill_shanghan",30 );
target->apply_condition("ill_zhongshu",30 );
}

me->start_busy(1); 
me->add_temp("apply/attack",-extra);
me->add_temp("apply/damage",-extra*2);
		return 1;
}
