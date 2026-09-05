// feijiane.c for huashan-jianfa by Jpei
// busy控制，如果点穴成功busy取大值，自己busy取小值，给机会继续feijian。

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

void remove_effect(object me);
void check_status(object me,object last_weapon, int last_time);
int perform(object me, object target)
{
        int skill;
		object weapon;
		string swordskill;

		if (!me->query("safari_skill/hs_jianyi"))
			return 0;
		if( (int)me->query("neili") < 1000  )
                return notify_fail("你的内力不够。\n");
		swordskill = me->query_skill_mapped("sword"); 
		if ( swordskill != "huashan-jianfa" && swordskill != "dugu-jiujian"
			&& swordskill!= "yunushijiu-jian" && swordskill!= "kuangfeng-kuaijian" 
			&& swordskill!= "yangwu-jian" && swordskill!= "xiyi-jian" )
				return notify_fail("你没有使用华山派的剑法，怎能使用『华山剑意』呢？\n");  
		if (!weapon=me->query_temp("weapon") || weapon->query("skill_type") != "sword" )
				return notify_fail("你手中无剑，怎能使用『华山剑意』呢？！\n");
    if( (int)me->query_temp("active_buffer/huashan-jianfa.jianyi") )
        return notify_fail("你已经在使用『华山剑意』。\n");
    if ((int)me->query_skill("huashan-jianfa", 1) < 200)
        return notify_fail("你的华山剑法等级不够，不能提升战斗力。\n");
		message_vision(HIC "$N默念华山剑法要诀，剑上出现一层寒芒。\n" NOR, me);
		me->add_temp("apply/kf_wound",30);
		me->add("neili", -(100+random(100)));
		skill=me->query_skill("sword", "huashan-jianfa"); 
    me->set_temp("active_buffer/family","华山派");
    me->set_temp("active_buffer/huashan-jianfa.jianyi/name", "华山剑意");                         //buff名称
    me->set_temp("active_buffer/huashan-jianfa.jianyi/last_time", time() + skill/5 );             //持续时间
    me->set_temp("active_buffer/huashan-jianfa.jianyi/effect1", "化学攻击威力增强30%");           //效果描述1   

    me->start_call_out(__FILE__, "remove_effect", skill/5, me);
		me->start_call_out(__FILE__, "check_status", 1, me,weapon, time() + skill/5);
    if( me->is_fighting() ) me->start_busy(3);

    return 1;
}

void check_status(object me,object last_weapon, int last_time)
{
	object weapon;
	string swordskill;
	
	if ( !me->query_temp("active_buffer/huashan-jianfa.jianyi") )
	  return ;
	
/*	if ( me->query_temp("active_buffer/huashan-jianfa.jianyi/last_time")!=last_time )
	  return;
*/	
	swordskill = me->query_skill_mapped("sword"); 
	if ( swordskill != "huashan-jianfa" && swordskill != "dugu-jiujian"
			&& swordskill!= "yunushijiu-jian" && swordskill!= "kuangfeng-kuaijian" 
			&& swordskill!= "yangwu-jian" && swordskill!= "xiyi-jian" )
		return remove_effect(me);
	
	if (!(weapon=me->query_temp("weapon")) || weapon!=last_weapon)
	{
		return remove_effect(me);
	}
	call_out("check_status",2,me,weapon);
	//me->start_call_out(__FILE__, "check_status", 2, me,weapon);
}

void remove_effect(object me)
{
  remove_call_out("remove_effect");

  if( me->query_temp("active_buffer/huashan-jianfa.jianyi") )
	{

	 me->add_temp("apply/kf_wound",-30);
	 me->delete_temp("active_buffer/huashan-jianfa.jianyi");
	 tell_object(me, "你剑上的寒芒渐渐消失不见。\n");
	}
}

