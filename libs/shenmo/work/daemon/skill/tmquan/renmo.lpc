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
		return notify_fail("［人魔式］只能对战斗中的对手使用。\n");
	extra = me->query_skill("tmquan",1) ;
	if(extra < 160 ) return notify_fail("你的［如意地魔连环八掌］不够熟练！\n");
	msg = HIR "\n$N双臂暴长，一招［人魔式］，双手拢向$n！" NOR;
	if(random((int)me->query("combat_exp")) >= (int)target->query("combat_exp")/2 || random(8)==0)
	{
	message_vision(msg+"\n",me,target);
	message_vision( HIB "$N躲闪不及，全身正被掌影罩住！ 一股蓝气从$N顶门喷涌而出！\n" NOR,target);
	target->receive_wound("qi",extra*2);
	me->receive_heal("qi",extra);

	target->receive_wound("jing",extra*2);
	me->receive_heal("jing",extra);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	}	
	else{
        weapon = me->query_temp("weapon");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

	}
	me->start_busy(2);
	return 1;
}
