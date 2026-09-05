// cimu.c

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int pp,damage,mm,tt;
	//pp=target->query_temp("pixie");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("刺目只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword"
        || weapon->query("id") != "xiuhua zhen")
                return notify_fail("你没有拿绣花针，怎么刺别人穴道？\n");

	if(me->query_skill("pixie-jian",1)<120)
		return notify_fail("你辟邪剑法不太熟练，不能使出「刺目」一式。\n");
	if(me->query("neili")<200)
		return notify_fail("你内力不够，不能使出「刺目」一式。\n");
	//if( target->is_busy() )

//		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

	msg = GRN "$N使出辟邪剑法法「刺目」诀，捻出一根绣花针，身形猛起，从$n的头上掠过的同时手中绣花针刺向$n的双目。\n";
	target->set_temp("pixie",(int)(target->query_temp("pixie")+10));
	pp=(int)target->query_temp("pixie");
	me->start_busy(random(3));
	mm=random((int)me->query_skill("dodge",1))+(int)me->query("dex");
	tt=random((int)target->query_skill("parry",1))+pp+(int)target->query("dex");
	if( target->is_busy() )
	me->set_temp("cimu",1);

	if(!target->is_busy()&&random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
	{
		msg += "$p眼前出现千万支剑影，心神大乱，被$P攻了个措手不及。\n" NOR;

	target->start_busy(3);
		me->set_temp("cimu",1);
	}
	else
	msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
	message_vision(msg, me, target);
	if((int)me->query_temp("cimu")==1&&mm>tt)
		{
		msg = RED"$p被$P刺个正着，惨叫一声，双手掩目，身子一歪，退后丈许！！\n" NOR;
		message_vision(msg, me, target);
		damage = 2*(int)me->query_skill("pixie-jian", 1);
                damage = damage/2 + random(damage);
                target->receive_damage("qi", damage+50,me);
                target->receive_wound("qi", damage,me);
                me->add("neili", - 150);
		target->start_busy(0);

		if (!target->query_temp("blind"))
		{
			target->set_temp("blind", 1);
			target->add_temp("apply/defense", - damage / 2);
			call_out("remove_effect", 3 + random(5), target, damage / 2);
		}
		me->start_busy(random(5));
	//	me->set_temp("cimu",0);
		target->set_temp("pixie",0);
		target->kill_ob(me);
		}
	me->set_temp("cimu",0);
	return 1;
}
void remove_effect(object me, int damage)
{
   if ( objectp(me) && me->query_temp("blind") )
   {
	me->delete_temp("blind);
	me->add_temp("apply/defense", damage);
	tell_object(me, "你的视力恢复了正常。\n");
   }
}