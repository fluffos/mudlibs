
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
		return notify_fail("［刀神］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	        extra = me->query_skill("ittouryu",1) ;
        if ( extra < 100) return notify_fail("你的［一刀流剑术］还不够纯熟！\n");
		if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 600 )
		return notify_fail("你的真气不够！\n");
	
	extra = (int)me->query_skill("ittouryu",1) / 10;
	if (extra >= 80) extra=80;
	me->add_temp("apply/attack", extra*2);	
	me->add_temp("apply/damage", 800);
	msg = HIR  "$N使出［圆月神刀斩］中的无上绝技－－刀神！"+ weapon->name() +"划着奇异的弧线，急斩$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	for(i=0;i<extra/5;i++)
	{
	msg = CYN "$N御技如神，刀气纵横！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add("neili",-30);
	}
	me->add_temp("apply/attack", -extra*2);
	me->add_temp("apply/damage", -800);
	me->start_busy(3);
	return 1;
}
