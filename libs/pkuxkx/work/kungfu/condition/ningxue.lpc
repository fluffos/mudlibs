inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int delete_condition(object me, int duration)
{
        me->delete_temp("death_cond_origin/ningxue");
		me->add_temp("apply/attack_speed", (int)me->query_temp("ningxue_poison/attack_speed"));
        me->delete_temp("ningxue_poison");
		me->delete_temp("active_debuff/ningxue_poison");
		return 1;
}

int update_condition(object me, int duration)
{
	int times = me->query_temp("ningxue_poison/times");
	int eff;
    if( duration < 1 ) 
    {
		delete_condition(me, duration);
        return 0;
    }
    me->set_temp("death_cond_id", "ningxue");
	me->add_temp("ningxue_poison/times", 1);
	
	if (times<1) times=1;

	me->add_temp("apply/attack_speed", -10);
	me->add_temp("ningxue_poison/attack_speed", 10);
    me->set_temp("active_debuff/ningxue_poison/name", "凝血毒");                       //buff名称
	
	eff = (int)me->query_temp("ningxue_poison/attack_speed");
    me->set_temp("active_debuff/ningxue_poison/effect1", "攻击速度-"+eff+"%");      //效果描述1
	
	F_POISON->poison_eff(me,"ningxue",(["qi":({1,1+random(10)}),"jing":({4,times+random(3)}),]),1); 

    me->apply_condition("ningxue", duration - 1);
	
    message_vision(HIR"$N全身一阵抽搐，感觉全身血液慢慢凝结，像是变成了浆糊一般。\n"NOR, me);
		
    return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}

