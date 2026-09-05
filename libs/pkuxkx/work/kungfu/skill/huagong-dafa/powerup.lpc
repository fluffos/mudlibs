// powerup.c
//modifid by cobra
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;
		string msg;
		
        if( target != me )
                return notify_fail("你只能用化功大法来提升自己的战斗力。\n");
        if( (int)me->query("neili") < 300  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");
        if( (int)me->query_skill("huagong-dafa", 1)<150)
                return notify_fail("你的化功大法等级不够，不能用来增强战斗力。\n");
		if (!me->query("safari_skill/xx_fire") && !me->query("safari_skill/xx_dushen"))
				return notify_fail("你还没有掌握化功大法的精髓，不懂得如何增强战斗力。\n");
		if (me->query("chushi")||me->query("family/family_name")!="星宿派")
				return notify_fail("只有纯星宿派弟子才能驱使化功大法增强战斗力。\n");
 
        skill = me->query_skill("force","huagong-dafa");

		if (me->query("safari_skill/xx_fire"))
		{
			msg = HIR "$N默运化功大法，一朵幽蓝色的火焰浮现在左肩上，火光若隐若现，十分诡异。\n" NOR;
			me->set_temp("apply/xx_fire", 1);
			me->add_temp("apply/attack_speed", -200);
			me->add_temp("apply/kf_wound", 10);
			me->add_temp("apply/enforce_enhance", 100);
			me->set_temp("powerup", 1);
			me->set_temp("active_force_buffer/huagong-dafa.powerup/name", "加力");                                  //buff名称
			me->set_temp("active_force_buffer/huagong-dafa.powerup/last_time", time() + skill/5 );              //持续时间
			me->set_temp("active_force_buffer/huagong-dafa.powerup/effect1", "幽冥火焰");       //效果描述1   
			me->set_temp("active_force_buffer/huagong-dafa.powerup/effect2", "化学伤害+10%");       //效果描述2  	
			me->set_temp("active_force_buffer/huagong-dafa.powerup/effect3", "攻击速度-200%");       	//效果描述2
		}
		else
		{
			msg = HIR "$N默运化功大法，浑身笼罩在一股黑气之中，面目扭曲，显得十分狰狞可怖。\n" NOR;
			me->set_temp("apply/xx_dushen", 1);
			me->add_temp("apply/attack_speed", 50);
			me->add_temp("apply/week_injure", 5);
			if (!me->query_temp("dushen"))
				F_POISON->empoison(me,"xx_poison2",1,"all");
			me->set_temp("powerup", 1);
			me->set_temp("active_force_buffer/huagong-dafa.powerup/name", "加力");                                  //buff名称
			me->set_temp("active_force_buffer/huagong-dafa.powerup/last_time", time() + skill/5 );              //持续时间
			me->set_temp("active_force_buffer/huagong-dafa.powerup/effect1", "毒神附体");       //效果描述1   
			me->set_temp("active_force_buffer/huagong-dafa.powerup/effect2", "受到物理伤害-5%");       //效果描述2  	
			me->set_temp("active_force_buffer/huagong-dafa.powerup/effect3", "攻击速度+50%");       	//效果描述2
		}

        me->start_call_out(__FILE__, "remove_effect", skill/5, me, skill/5);

		me->add("neili", -100);
        message_vision(msg, me);
        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}
void remove_effect(object me, int amount)
{
	if (me->query_temp("apply/xx_fire"))
	{
		me->delete_temp("apply/xx_fire");
		me->add_temp("apply/attack_speed", 200);
		me->add_temp("apply/kf_wound", -10);
        me->add_temp("apply/enforce_enhance", -100);
		me->set("jiali", 0);
	}
	else if (me->query_temp("apply/xx_dushen"))
	{
		me->delete_temp("apply/xx_dushen");
		me->add_temp("apply/attack_speed", -50);
		me->add_temp("apply/week_injure", -5);
		if (!me->query_temp("dushen"))
			F_POISON->depoison(me);
	}
    me->delete_temp("powerup");
    me->delete_temp("active_force_buffer/huagong-dafa.powerup");
    tell_object(me, "你的化功大法运行完毕，将内力收回丹田。\n");
}

