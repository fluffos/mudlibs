// enhance.c
//inherit SSERVER;
#include <ansi.h>

int adcp(int cp)
{
	if (cp>=3) return 4;
	else return cp;
}

int exert(object me, object target)
{
	string force;
	int lvl, ad, cp, neili=0, i=1;

	if (me != target)
		return notify_fail("你只能用内功强化自己的身体。\n");

	if ( me->query("myVeins/level")<4 )
		return notify_fail("你还没有打通第4层经脉，无法使用「强筋健骨」。\n");

	force=me->query_skill_mapped("force");
	lvl=me->query_skill("force");

	if ( lvl < 1500 || !stringp(force) )
		return notify_fail("你的内功修为还不够，无法使用「强筋健骨」。\n");

	if ((int)me->query("max_neili") < 5000 )
		return notify_fail("你的内力修为不够。\n");

	if ((int)me->query("neili") < 3000 )
		return notify_fail("你的内力不够。\n");
  
	if ( me->query_temp("active_force_buffer/force.enhance") )
		return notify_fail("你正在使用「强筋健骨」。\n");

	
	me->add("neili", -100);

	cp = (int)me->query("myVeins/足太阳膀胱经/completed");
	if (cp>0)
	{
		i++;
		ad = adcp(cp);
		neili += ad*2;
		me->add_temp("apply/week_injure", ad);
		me->set_temp("active_force_buffer/force.enhance/effect"+i, "普通伤害抗性+"+ad+"%");              //效果描述
		me->set_temp("force_enhance/week_injure", -ad);
	}
	
	cp = (int)me->query("myVeins/足少阴肾经/completed");
	if (cp>0)
	{
		i++;
		ad = adcp(cp);
		neili += ad*2;
		me->add_temp("apply/kf_def_wound", ad);
		me->set_temp("active_force_buffer/force.enhance/effect"+i, "化学伤害抗性+"+ad+"%");              //效果描述
		me->set_temp("force_enhance/kf_def_wound", -ad);
	}

	cp = (int)me->query("myVeins/手厥阴心包经/completed");
	if (cp>0)
	{
		i++;
		neili += 5;
		ad = adcp(cp)*5;
		me->add_temp("apply/AllPoisonsImmune", ad);
		me->set_temp("active_force_buffer/force.enhance/effect"+i, "毒抗性+"+ad+"%");              //效果描述
		me->set_temp("force_enhance/AllPoisonsImmune", -ad);
	}
	
	cp = (int)me->query("myVeins/手少阳三焦经/completed");
	if (cp>0)
	{
		i++;
		neili += 10;
		ad = adcp(cp)*5;
		me->add_temp("apply/anti_all_busy", ad);
		me->set_temp("active_force_buffer/force.enhance/effect"+i, "状态抗性+"+ad+"%");              //效果描述
		me->set_temp("force_enhance/anti_all_busy", -ad);
	}
	
	if (i<2)
		return notify_fail("你的经脉修为还不够，无法使用「强筋健骨」。\n");
	
	me->add_temp("apply/neili_recover", -neili);
	me->set_temp("force_enhance/neili_recover", neili);
	me->set_temp("active_force_buffer/force.enhance/name", "强筋健骨");                         //buff名称
	me->set_temp("active_force_buffer/force.enhance/last_time", time() + 120 + lvl/10 );                 //持续时间
	me->set_temp("active_force_buffer/force.enhance/effect1", "内力恢复-"+neili+"点/秒");       //效果描述  

	message_vision(HIC"$N默运真气行走四肢百骸，强化自身的筋骨。\n"NOR, me);
	
	me->start_call_out(__FILE__, "remove_effect", 120+lvl/10, me);
	if( me->is_fighting() ) me->start_busy(2);
	
	return 1;
}

void remove_effect(object me)
{
	me->add_temp("apply/week_injure", (int)me->query_temp("force_enhance/week_injure"));
	me->add_temp("apply/kf_def_wound", (int)me->query_temp("force_enhance/kf_def_wound"));
	me->add_temp("apply/AllPoisonsImmune", (int)me->query_temp("force_enhance/AllPoisonsImmune"));
	me->add_temp("apply/anti_all_busy", (int)me->query_temp("force_enhance/anti_all_busy"));
	me->add_temp("apply/neili_recover", (int)me->query_temp("force_enhance/neili_recover"));
	me->delete_temp("force_enhance");
	
	me->delete_temp("active_force_buffer/force.enhance"); 
	tell_object(me, HIY"你的真气运行完毕，自四肢百骸缓缓收归丹田。\n"NOR);
}