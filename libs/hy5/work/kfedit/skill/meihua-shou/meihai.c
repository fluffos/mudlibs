// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［梅海］只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon"))
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-200);
	weapon = me->query_temp("weapon");
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	lvl = (int) me->query_skill("unarmed") / 50 + 1;
	msg = HIR "$N双手幻出漫天梅花，飞雪似的向$n落来！" NOR;
	if( random(myexp * lvl) > yourexp )
	{
		message_vision(msg + "\n", me, target);
		msg = "结果$n被$N攻了个手忙脚乱！\n";
		message_vision(msg, me, target);
		target->start_busy(4);
	}
	else
		        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
			me->start_busy(2);
	return 1;
}
