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
	string msg;
	if(me->is_busy())
	{
		return notify_fail("你正忙着呢。\n");
	}

        for(i=1;i<3+random(2);i++)
   {

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("天地无用只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("guihun-jian", 1) < 80 )
		return notify_fail("你的归魂剑法不够娴熟，不会使用「天地无用」。\n");

	
	if( (int)me->query("neili") < 300  ) 
		return notify_fail("你的内力不够。\n");

	

	msg = HIY"$N双手握起"NOR + weapon->name() + HIY"，剑芒暴长，刹那间天昏地暗，飞沙走石,"NOR+weapon->name()+HIY"从一片迷茫之中\n神奇般的突出，直刺目标!\n"NOR;
	message_vision(msg, me, target);
	dam=me->query_skill("guihun-jian",1)+me->query("neili")/100+
        me->query("str")*me->query("jiali")/3-target->query_skill("dodge",1);
	if(dam < 0) dam=100;
	if(random(me->query("jingli")) > 1000)
	{
		target->receive_damage("qi",dam);
		target->receive_damage("jing",dam/3);
		target->add("eff_qi",-dam/3);
		message_vision("$N被$n剑气所迫，哇的吐出一口鲜血！！\n",target,me);
	}
	skill = (int)me->query_skill("guihun-jian",1);
	me->add_temp("apply/attack", skill/2);
	me->add_temp("apply/dodge", skill/8);
	

          call_out("remove_effect", 10 ,me, skill/2, skill/8);

	me->add("neili", -80);
     }
	me->start_busy(2);
	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
     message_vision(HIW"$N脸上的杀气渐渐退下来了！\n"NOR,me);
	me->add_temp("apply/attack", - a_amount);
        me->add_temp("apply/dodge", -d_amount);
	me->delete_temp("begin");
//        me->start_busy(2);
}
