// hunpofeiyang.c 魂魄飛揚
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

//	skill = me->query_skill("hunyuan-zhang",1);

	if( !me->is_fighting() )
	    	return notify_fail("「魂魄飛揚」只能在戰斗中使用。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的內力還不夠高！\n");

          if( (int)me->query_skill("cuff") < 200 )
		return notify_fail("你的拳法還不到家，無法使用魂魄飛揚！\n");

          if( (int)me->query_skill("qishang-quan", 1) < 200)
		return notify_fail("你七傷拳的修為不夠，不能使用魂魄飛揚! \n");

	if( me->query_skill_mapped("cuff") != "qishang-quan") 
		return notify_fail("你沒有激發七傷拳，無法使用魂魄飛揚！\n");
 
	msg = HIY "$N大喝一聲，使出七傷拳的絕技「魂魄飛揚」，雙拳勢如雷霆，向$n擊去。\n"NOR;
	message_combatd(msg, me, target);
 
	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-100);

		msg = HIG "$n只覺得胸前一陣劇痛，“哇”的一聲噴出一口鮮血！\n"NOR;
		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

                  qi_wound = neili_wound / 10;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");

		target->add("neili", -neili_wound);
		target->receive_wound("qi", qi_wound);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg = HIG "只見$n不慌不忙，輕輕一閃，躲過了$N的必殺一擊！\n"NOR;
		if(userp(me))
			me->add("neili",-100);
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
