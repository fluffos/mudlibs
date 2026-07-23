// 尾巴摇摇

#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
		object weapon;
	
extra = me->query_skill("dragon");
if(me->is_busy())
		return notify_fail("你现太忙，用不出绝技！！\n");
		

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［尾巴摇摇］只能对战斗中的对手使用。\n");
	
me->add_temp("apply/attack",extra*3);
me->add_temp("apply/damage",extra*3);

	
weapon = me->query_temp("weapon");
	
msg = HIY  "$N"HIY"巨大无比的身躯开始巨烈的晃动,强大的龙尾连连甩动！\n" NOR;
	message_vision(msg,me,target);
	msg = HIC  " 摇！龙尾向$n上身突刺而来!" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "再摇！！龙尾对着$n下身横扫而过!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "最后一摇！！！龙尾对着$n全身压了下来!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


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

    me->start_busy(1); 	
me->add_temp("apply/attack",-extra*3);
me->add_temp("apply/damage",-extra*3);
		return 1;
}
