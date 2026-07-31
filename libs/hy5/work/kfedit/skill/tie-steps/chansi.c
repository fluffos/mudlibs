// chansi.c
//written by kouga
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
	string msg;
	object weapon;
	skill = me->query_skill("tie-steps",1);
	if(skill < 100) return notify_fail("你的铁血十二势太差了！\n"); 
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［缠丝势］只能对战斗中的对手使用。\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
        if( (int)me->query("neili") < 100 )     return
        notify_fail("你的内力不够。\n");
        if( (int)target->query_temp("chansi") ) return 
	notify_fail("你已经在施展［缠丝势］了。\n");
       	if((int)target->query("combat_exp") < random((int)me->query("combat_exp")*skill/40))
	{
		me->add("neili", -100);
        	message_vision( HIR
		"$N轻身一跃，使出［缠丝势］，$n的身形受你的影响，变的生涩起来！\n" NOR, me,target);
        	target->add_temp("apply/dodge", -skill/3);
		target->add_temp("apply/parry",-skill/3);       
        	target->set_temp("chansi", 1);
        	target->start_call_out( (: call_other, __FILE__, "remove_effect", target, 
-skill/3 :), skill/5);
        	me->start_busy(1);
	}
	else
	{
		msg = "可惜$N看出了$n的身法，向你迅然攻击！";
		COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
        	me->start_busy(1);
	}
        return 1;
}

void remove_effect(object target, int amount)
{
        target->add_temp("apply/dodge", - amount);
	target->add_temp("apply/parry",- amount);
        target->delete_temp("chansi");
        message_vision("$N终于摆脱了［缠丝势］的影响。\n",target);
}
 
