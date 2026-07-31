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
		return notify_fail("［四起金龙］只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "staff")
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-200);
	weapon = me->query_temp("weapon");
	extra = me->query_skill("staff",1) / 10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N"HIR"低呼佛号，内力聚于双臂，舞动手中的"+ weapon->name() +"［四起金龙］第一势 ##龙现于野##，闪电般的扑向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIG  "$N"HIG"微探双臂，凭空一点,手中的"+ weapon->name() +"对准$n使出［四起金龙］的第二势  ##龙翔于天##  ！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIC  "$N"HIC"一声长啸，猛然探出手中的"+ weapon->name() +"使出［四起金龙］第三势 ##龙游于渊## ！ 幻出条条金磷飞龙，闪电般的扑向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIY  "$N"HIY"把手中的"+ weapon->name() +"舞动如飞，向$n使出［四起金龙］第四势 ##龙入九天## ！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
