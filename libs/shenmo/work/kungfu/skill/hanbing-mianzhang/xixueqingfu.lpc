// xixueqingfu.c 吸血青蝠
 
#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound;
        int extra;
	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("hanbing-mianzhang",1);

	if( !(me->is_fighting() ))
		return notify_fail("「吸血青蝠」只能对战斗中的对手使用。\n");

 	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("你现在内力太弱，不能使用「吸血青蝠」。\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你使用了武器。\n");

	if( skill < 60)
		return notify_fail("你的「寒冰绵掌」等级不够, 不能使用「吸血青蝠」！\n");

	if( me->query_skill("dodge",1) < 150 )
		return notify_fail("你的轻功不够，无法运用「吸血青蝠」！\n");
 
	msg = HIC "$N突然如同「吸血青蝠」，欺近$n的身前，张嘴便向$n的咽喉咬去。\n"NOR;
	message_combatd(msg, me, target );
 if ((int)me->query_skill("jiuyang-shengong",1) > 50)
{

        extra = me->query_skill("jiuyang-shengong",1) / 10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);

        msg =  HIR "第一咬\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIR "第二咬\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIR "第三咬\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);    
        me->add_temp("apply/damage", -extra);

}
	ap = me->query("combat_exp") + skill * 500;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-200);

		msg = HIG "$n只觉得咽喉一阵剧痛，$N正在狂吸$n的鲜血！\n"NOR;
		neili_wound = 500 + random(skill);
		if(neili_wound > target->query("qi"))
			neili_wound = target->query("qi");

		qi_wound = neili_wound / 3;
		if (target->query("qi") > neili_wound)
		target->add("qi",-neili_wound);
		if (target->query("eff_qi") > neili_wound)
		target->add("eff_qi",-neili_wound);
		me->start_busy(2);
	       me->add("qi",qi_wound);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);

	}
	else
	{
		msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的利齿！\n"NOR;
		if(userp(me))
			me->add("neili",-100);
		me->start_busy(2);
		message_combatd(msg, me, target);
	}
	if(!target->is_fighting(me)) me->fight_ob(target);

	return 1;
}
