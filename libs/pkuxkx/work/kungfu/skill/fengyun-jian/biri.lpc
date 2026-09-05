// biri.c 风云蔽日 by Vast

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int pp,damage,mm,tt;
	object weapon;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『风云蔽日』只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你手中无剑，怎么使用『风云蔽日』？\n");

	if( me->is_busy() )
	return notify_fail("你自顾不暇，哪有功夫施展绝技！\n");
	
	if( target->query_temp("blind") )
	return notify_fail("对手双目难睁，此时正是痛下杀手的好时机！\n");
	
	if(me->query_skill("fengyun-jian",1)<120)
		return notify_fail("你风云剑法不太熟练，不能使出『风云蔽日』一式。\n");
	if(me->query("neili")<200)
		return notify_fail("你内力不够，不能使出『风云蔽日』一式。\n");

	msg = HIG "$N使出风云剑法『风云蔽日』的绝招，身形猛起，剑走偏锋，变化莫测，试图扰乱$n。\n";
	

	me->start_busy(2 + random(2));
	
	mm=random(me->query_skill("dodge"));
	tt=random(target->query_skill("parry"));
//	pp = target->query_temp("apply/dodge");
	pp = me->query_skill("fengyun-jian");
//	pp = pp / 5;
	
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		msg += HIG"$p被剑影刺得眼花缭乱，一时间心神大乱。\n" NOR;

		target->add_busy(3 + random(4));//有可能连续busy对手
		me->set_temp("cimu",1);
	}
	else
	msg += HIY"可是$p看破了$P的企图，并没有上当。\n" NOR;
	
	if(me->query_temp("cimu") && mm>tt)
		{
		msg += RED"只见$P剑光一闪，$n躲闪不及，只听一声惨叫，$p痛苦地捂住了自己的眼睛……\n" NOR;

		damage = (int)me->query_skill("fengyun-jian", 1);
    damage = damage/2 + random(damage);
    target->receive_damage("qi", damage, me);
    target->receive_wound("qi", damage, me);
    me->add("neili", - 150);
    me->start_busy(0);

		target->set_temp("blind", 1);
		target->add_temp("apply/dodge", - pp);
		call_out("remove_effect", 5 + random(5), target, pp);
		}

		me->set_temp("cimu",0);		
		message_vision(msg, me, target);
        COMBAT_D->report_status(target);
	
	return 1;
}
void remove_effect(object me, int pp)
{
		me->delete_temp("blind");
		me->add_temp("apply/dodge", pp);
		tell_object(me, HIG"你终于从混乱中恢复了过来。\n"NOR);
}