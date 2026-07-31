// hua.c 化骨绵掌

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int extra;
	extra = me->query_skill("huagu-mianzhang",1);
	if( !target ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

	if( !target || !target->is_character() )
		return notify_fail("辣手化骨只能对对手使用。\n");

	if( target->query_temp("huagu")>3)
		return notify_fail("对手已经中了不少辣手化骨了，你再打也没用了。\n");


	if( (int)me->query_skill("shenlong-xinfa", 1) < 50 )
		return notify_fail("你的神龙心法不够娴熟，不能化骨。\n");

	if( (int)me->query_skill("huagu-mianzhang", 1) < 40 )
		return notify_fail("你的化骨绵掌不够娴熟，不能化骨。\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("你的内力不够，不能化骨。\n");

        me->add("neili", -100);

	msg = MAG "$N掌出如风轻轻落在$n肩头上。\n"NOR;

	me->start_busy(2);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) 
{
		msg += MAG "结果只听扑的一声，$p被$P一掌拍中！\n" NOR;
		msg += MAG "$p只觉得全身暖洋洋的，感到有点轻飘无力轻。\n" NOR;
		target->add_temp("apply/attack", -extra/5);
		target->add_temp("apply/dodge", -extra/5);
		target->add_temp("apply/defense", -extra/5);
		target->add_temp("huagu",1);
        target->apply_condition("snake_poison",10);
        target->apply_condition("cold_poison",10);
		msg += HIB "忽然一股寒气优似冰箭，循着手臂，迅速无伦的射入$p胸膛\n" NOR;
                me->start_call_out( (: call_other, __FILE__, "remove_effect",target,extra/5, extra/5:), extra/5);
}
	 else {
		msg += CYN"可是$p急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(3);
	}

	message_combatd(msg, me, target);
	if( !target->is_fighting(me) ) target->fight_ob(me);
	return 1;
}
void remove_effect(object target,int aamount, int damount)
{
if (target)
{
		target->add_temp("apply/attack", aamount);
		target->add_temp("apply/dodge", aamount);
		target->add_temp("apply/defense", aamount);
target->start_busy(3);
               message_combatd(YEL"$N从猛烈的攻击中摆脱了出来，连退数步,稳住了脚步\n"NOR, target);
}
}
