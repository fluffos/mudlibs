// jinglei.c 弹指惊雷
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, dp, wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("tanzhi-shentong",1);

	if( !(me->is_fighting() ))
		return notify_fail("「弹指惊雷」只能在战斗中使用。\n");

	if ( objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你使用了武器。\n");

	if( skill < 120)
		return notify_fail("你的弹指神通等级不够, 不能使用「弹指惊雷」！\n");

	if( me->query("neili") < 150 )
		return notify_fail("你的内力不够，无法运用「弹指惊雷」！\n");
 
	msg = HIC "$N使出弹指神通之「弹指惊雷」, 顿时眼内精光暴射，\n";
	message_combatd(msg, me, target);
 
	dp = target->query("combat_exp");
	if( dp < 1 )
		dp = 1;
	if( random(me->query("combat_exp")) > random(dp)) 
	{
		if(userp(me))
			me->add("neili",-150);
		msg = "$n只觉得眼前一花，气海穴上微微一痛，全身真气狂泄而出！\n" ;
		if ( objectp(weapon2 = target->query_temp("weapon")))
		{
			msg += "同时手腕一麻，手中";
			msg += weapon2->name();
			msg += "脱手而出！\n" NOR;
			weapon2->move(environment(me));
		}
		wound = 300 + random(200);
		if((int)target->query("neili") < wound)
			wound = target->query("neili");
		target->add("neili", -wound);
		target->receive_wound("jing", wound/5);
		target->receive_wound("qi", wound/5);
		target->start_busy(8);
		me->start_busy(2);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);

	}
	else
	{
		msg = "可是$n的看破了$N的企图，立刻采取守势，使$P的「弹指惊雷」没有起到作用。\n"NOR;
		me->start_busy(1);
		message_combatd(msg, me, target);
	}

	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);

	return 1;
}
