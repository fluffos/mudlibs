#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="将军府")
        	return notify_fail("你不是将军府弟子，不能使用这项技能！\n");
	if( !target ) target = me;        	
	if( target != me ) 
                return notify_fail("你只能用静心诀提高自己的警觉。\n");
        if( (int)me->query("force") < 100 )     
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("lengquan-force",1);

        me->add("bellicosity", -skill/2);
	if((int)me->query("bellicosity") <= 0){
		me->set("bellicosity", 1);
	}
        me->add("force", -80);
        message_vision(HIR"$N"HIR"微一凝神，运起静心诀，登时心平气稳，于周围一切警觉有加。\n"NOR, me);
        me->add_temp("apply/dodge", skill/5);
        me->set_temp("jjf_jingxin",skill/5);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me,skill/5 :), skill);

        if( me->is_fighting() ) 
        	me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
 	if(me)
 	{
        	me->add_temp("apply/dodge", -amount);
        	me->delete_temp("jjf_jingxin");
        	me->delete_temp("powerup");
        	tell_object(me,"你的静心诀运行一周天完毕，将内力收回丹田。\n");
	}
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：静心诀
        内功所属：冷泉神功
        内功效果：一定时期内增加自身的闪避率
        	  同时降低自身的杀气
                  战斗中使用自身busy2秒
                  不能与其他增益型状态叠加
        内功条件：
                  将军府弟子
        	  人物等级 10 级
        	  内力100点，消耗80点
STR;
        me->start_more(str);
        return 1;
}

void remove()
{
	int amount,i;
	object me,*usr = users();
	if( i=sizeof(usr)>0 )
	{
		while(i--)
		{
			if( !usr[i] || !environment(usr[i])
			 || !objectp(usr[i]) )
				continue;
			if( usr[i]->query_temp("jjf_jingxin") )
			{
				me = usr[i];
				amount = me->query_temp("jjf_jingxin");
        			me->add_temp("apply/dodge", -amount);
        			me->delete_temp("jjf_jingxin");
        			me->delete_temp("powerup");
        			tell_object(me,"你的静心诀运行一周天完毕，将内力收回丹田。\n");
			}
		}
	}
} 