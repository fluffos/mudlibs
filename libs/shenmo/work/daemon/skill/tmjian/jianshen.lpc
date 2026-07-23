
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i,lv;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［剑神］只能对战斗中的对手使用。\n");

        if( !(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "sword" )
        return notify_fail("你手中没有装备剑类武器！\n");
        if( (int)me->query("neili")<500)
        return notify_fail("你现在内力太弱，不能使用！\n"NOR);
        
	weapon = me->query_temp("weapon");
	extra = me->query_skill("tmjian",1) / 4;
	
	if (extra> 200) extra=200;
	me->add_temp("apply/attack", extra*2);	
	me->add_temp("apply/damage", extra*2);
	msg = HIR  "$N使出［圆月神刀斩］中的无上绝技－－剑神！"+ weapon->name() +"划着奇异的弧线，急斩$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	lv=extra/8;
	if (lv > 8) lv=8;
	me->set_temp("action_flag", 1);
	for(i=0;i<lv;i++)
	{
	msg = CYN "第"+(i+1)+"剑！$N御技如神，剑气纵横！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add("neili",-30);
	}
	me->delete_temp("action_flag");
	me->add_temp("apply/attack", -extra*2);
	me->add_temp("apply/damage", -extra*2);
	
	me->start_busy(3);
	return 1;
}
