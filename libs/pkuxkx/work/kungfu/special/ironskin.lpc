// ironskin.c 铜皮铁骨
//update by yhzzyahoo@2015.6.5
#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIC "铜皮铁骨" NOR; }

int perform(object me, string skill)
{
        int count;
   //     int count2;
		int c_time,m_count;
        if(me->query("age")<18)
                return notify_fail("你还未成年，不能使用特殊技能。\n");
//        if ( time()- me->query_temp("no_ironskin")<=210 )
//                return notify_fail("你刚刚使用过铜皮铁骨，精力还未平复。\n");
        if (me->query("qi") < 300)
                return notify_fail("你的体力不支，无法竭力提升自己的防御力。\n");
	    if (me->query("jingli")<200)
             return notify_fail("你的精力不足，无法使用铜皮铁骨。\n");  
	    if (me->query("neili")<200)
             return notify_fail("你的内力不足，无法使用铜皮铁骨。\n");  


        if (me->query_temp("special_skill/ironskin", 1))
                return notify_fail("你已经竭力提升你自己的防御力了。\n");
        message_vision(HIC "$N微一凝神，气沉丹田，全身肌肤如铁。\n" NOR, me);
        count=(int)me->query_skill("parry",1)*2;
    //    count2=(int)me->query_skill("parry",1)/4;
		if (me->query("special_level/ironskin")>2)
		{
			m_count=20;
		}
		else
		{
			if (me->query("special_level/ironskin")>1)
			{
				m_count=10;
			}
			else
			{
				m_count=0;
			}
		}
		//kf_def_wound
		c_time = 60 + random(30) + m_count*10;
//        me->receive_damage("qi", 40 + m_count*15 + random(40));
	    me->add("neili",-200);
		me->add("jingli",-200);
		me->set_temp("special_skill/ironskin", 1);
//        me->set_temp("no_ironskin",time());
        me->add_temp("apply/armor", count);
        me->add_temp("apply/defense", count/2);
//		me->set_temp("active_force_buffer/special.ironskin/last_time", time() + c_time);       //持续时间
        me->set_temp("active_force_buffer/special.ironskin/name", HIC "铜皮铁骨" NOR );        //buff名称
		me->set_temp("active_force_buffer/special.ironskin/effect1", "护甲+"+count+"点");       //效果描述1 
        me->set_temp("active_force_buffer/special.ironskin/effect2", "防御+"+count/2+"级");       //效果描述2 
		if (m_count>0)
		{
			me->add_temp("apply/kf_def_wound", m_count);
			me->add_temp("apply/anti_all_busy", m_count);
			me->set_temp("active_force_buffer/special.ironskin/effect3", "化学抗性+"+m_count+"%");       //效果描述3
			me->set_temp("active_force_buffer/special.ironskin/effect4", "状态抗性+"+m_count+"%");       //效果描述3
		}
		me->start_busy(1+random(2));
//		call_out("remove_effect", c_time, me, count, m_count);
		return 1;
}

void remove_effect(object me, int count,int m_count)
{
        me->delete_temp("special_skill/ironskin", 1);
        me->add_temp("apply/armor", -count);
        me->add_temp("apply/defense", -count/2);
        me->add_temp("apply/kf_def_wound", -m_count);
	    me->delete_temp("active_force_buffer/special.ironskin");
		me->add("jingshen",-200);
        tell_object(me, "一口气松懈下来，你不在处于防御状态。\n");
}
