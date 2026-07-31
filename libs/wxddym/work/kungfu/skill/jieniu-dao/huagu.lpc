// /kungfu/skill/gu.c 化骨刀
#include <ansi.h>

string query_name() { return "化骨刀"; }

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

if( me->query("family/family_name") != "血河派" ) 
            return notify_fail("你不理解血河派的信念，怎么用的出他们的武功。\n"); 

		damage = (int)me->query_skill("jieniu-dao", 1);

                damage = random(damage)*10;

	if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("「化骨刀」只能对战斗中的对手使用。\n");

	if( !objectp(me->query_temp("weapon")) )
		return notify_fail("你空手怎么能使用「化骨刀」！\n");		

	if( (int)me->query_skill("jieniu-dao", 1) < 60 )
		return notify_fail("你的解牛刀法不够娴熟，不会使用「化骨刀」!\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("你现在内力太弱，不能使用「化骨刀」!\n");

	msg = CYN "$N默运神功，使出「化骨刀」，单刀平推攻向$n。\n"NOR;

          if (me->query_skill("jieniu-dao") > target->query_skill("force")/3 )
	{
		me->start_busy(random(2));
		target->start_busy(random(3));

		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
                me->add("neili", -damage/3);

		if( damage < 40 )
			msg += HIY"结果$n被$N一刀斩中，闷哼一声。\n"NOR;
        else if( damage < 80 )
			msg += HIY"结果$n被$N一刀斩中，「嘿」地一声退了两步。\n"NOR;
        else if( damage < 160 )
			msg += RED"结果$n被$N一刀斩中，连退了五六步！\n"NOR;
		else
			msg += HIR"结果$n被$N一刀斩中，眼前一黑，伤口血涌如柱！\n"NOR;
		
	}
	else 
	{
		me->start_busy(random(2));
		me->add("qi", -(damage/2));
		me->add("eff_qi", -(damage/5));
		msg += CYN"可是$p看破了$P的企图，身形一转，回击过去。\n"NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
