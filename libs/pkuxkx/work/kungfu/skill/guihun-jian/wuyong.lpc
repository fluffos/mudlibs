//天地无用

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int skill,i,dam;
	int times;
	string msg;
	if(me->is_busy())
	{
		return notify_fail("你正忙着呢。\n");
	}
	times = 3+random(2);
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("天地无用只能对战斗中的对手使用。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                {
        if (!objectp(weapon = me->query_temp("secondary_weapon"))
                || (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");
             }

	if( (int)me->query_skill("guihun-jian", 1) < 200 )
		return notify_fail("你的归魂剑法不够娴熟，不会使用「天地无用」。\n");
	
	if( (int)me->query("pkscore") < 10000 )
	{
		return notify_fail("离开刀头舔血的杀手生活太久，你已经不能使出「天地无用」了。\n");
	}

    for(i=1;i<times;i++)
   {
	if( (int)me->query("neili") < 300  ) 
		return notify_fail("你的内力不够。\n");

		msg = HIY"$N双手握起"NOR + weapon->name() + HIY"，剑芒暴长，刹那间天昏地暗，飞沙走石,"NOR/*+weapon->name()*/+HIY"从一片迷茫之中\n神奇般的突出，直刺目标!\n"NOR;
		message_vision(msg, me, target);
		dam=me->query_skill("guihun-jian",1)+me->query("neili")/10+
			me->query("str")*me->query("jiali")/3-target->query_skill("dodge",1);
		if(dam < 0) dam=100;
		if(dam > 5000 ) dam=5000;
//B+			
		if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 4, me, target) )
		{
			F_KUNGFU->hit_wound("qi", dam, dam/3, me, target);
			F_KUNGFU->hit_wound("jing", dam/3, 0, me, target);
			message_vision("$N被$n剑气所迫，哇的吐出一口鲜血！！\n",target,me);
            COMBAT_D->report_status(target);
		}
		target->add_busy(random(2));
		me->add("neili", -300);
    }
	me->add("pkscore",-1);
	me->add_busy(3);
	return 1;
}