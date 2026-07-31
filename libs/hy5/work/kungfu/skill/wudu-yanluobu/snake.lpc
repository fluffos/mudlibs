// snake.c  金蛇游身

#include <ansi.h>
#include <combat.h>
// inherit F_CLEAN_UP;
inherit F_SSERVER;
void remove_effect(object me, int amount);

int perform(object me, object target)
{
       object ob;
	int skill,tg_skill,time;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「金蛇游身」只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("wudu-yanluobu", 1) < 50 )
		return notify_fail("你的五毒烟萝步火候不够，不能使出「金蛇游身」。\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("你现在内力太弱，不能使用「金蛇游身」。\n");

        if( (int)me->query_skill("wudu-shengong",1) < 50 )
                return notify_fail("你的五毒神功修为还不够！\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正手忙脚乱，你还乱转什么，赶快进攻吧！\n");
			
	msg = HIC "$N身行忽的一变，使出「金蛇游身」的绝技，身法越来越快。\n\n\n只见$N飞快的绕场游走，瞻之在前，望之在后，一时间到处都是$N的身影。\n"NOR;
	message_vision(msg, me, target);
       time = (int)me->query_skill("wudu-yanluobu",1)/50+2;
       skill = (int)me->query_skill("wudu-yanluobu",1)
             + (int)me->query_skill("dodge",1);
       tg_skill = (int)target->query_skill("dodge",1);
	me->add("neili", -100);
       if ((int)random(me->query("combat_exp"))+skill*600 > (int)random(target->query("combat_exp")))
       {
       target->start_busy(time);
	msg = HIR"$n不由得一阵手足无措，被$N连攻数招！\n"NOR;
	message_vision(msg, me, target);
       return 1;
        }
       else
        {
       me->start_busy(2);
	msg = HIR"可是$n以静制动，紧守门户，丝毫不受$N的影响,$N自己倒累的满头大汗！\n"NOR;
	message_vision(msg, me, target);
       }
	return 1;
}
