// 浩然正气决.c
// creat by yhzzyahoo@nx
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill, level, dur, cd_time;

		if (!me->query("safari_skill/tdh_zhengqi"))
		{
			return 0;
		}
        if( target != me ) 
            return notify_fail("你只能用浩气苍冥功提升自己的战斗力。\n");
        if( (int)me->query("neili") < 1000 ) 
            return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("cmg/zhengqi")) 
            return notify_fail("你已经在运功中了。\n");
		if (time() < me->query("cmg/zhengqi_cd_time"))
		{
			return notify_fail("你刚刚使用过『浩然正气决』，气息还未平复。\n");

		}
        skill = me->query_skill("cangming-gong",1);
		if (skill < 500)
		{
            return notify_fail("你的浩气苍冥功还不够，无法使用『浩然正气决』。\n");
		}
		if(me->query("family/family_name")!="天地会") 
			return notify_fail("非天地会成员无法体会到浩然正气。\n");
		level = skill/500;
		if (level > 3)
		{
			level = 3;
		}
		dur = skill / 120;
		if (dur < 6)
		{
			dur = 6;
		}
		if (dur > 12)
		{
			dur = 12;
		}
		if (skill < 1800)
		{
			cd_time = (2520 - skill)>>2;
		}
		else
		{
			cd_time = 180;
		}

		if (me->query("chushi/done") || me->query("betrayer"))
		{
			dur >>=1;
			level = 1;
			cd_time <<=1;
		}
		
        message_combatd(HIR "$N慷慨长啸，浩然正气充满全身：天地有正气，杂然赋流形！\n" NOR, me);
        me->add("force", -skill);
		me->set("cmg/zhengqi_cd_time",time()+cd_time);
		me->set_temp("cmg/zhengqi/point",level);
		me->set_temp("cmg/zhengqi/times",0);
   
        me->set_temp("active_force_buffer/cangming-gong.zhengqi/name", "浩然正气决");                                  //buff名称
        me->set_temp("active_force_buffer/cangming-gong.zhengqi/last_time", time() + dur);              //持续时间
        me->set_temp("active_force_buffer/cangming-gong.zhengqi/effect1", "大幅度提高绝招命中率");       //效果描述1   
        
        me->start_call_out(__FILE__, "remove_effect", dur, me);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me)
{
       me->delete_temp("cmg/zhengqi");
       me->delete_temp("active_force_buffer/cangming-gong.zhengqi");
       tell_object(me, "浩然正气决运功完毕，天地正气长久回荡！\n");
}

