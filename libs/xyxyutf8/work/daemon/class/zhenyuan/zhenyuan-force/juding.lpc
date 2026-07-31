// juding.c
#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{        
	int skill,time;
	if( me->query_level()<15 )
		return notify_fail("你的人物等级不够。\n");   
	if( !target ) target = me;		     
	if( target != me )                 
        	return notify_fail("你只能用『三花聚顶』提高自己的攻击力。\n");        
	if( (int)me->query_temp("powerup") )                 
        	return notify_fail("你已经在运功中了。\n");
	if( (int)me->query("force") < 500 )                     
        	return notify_fail("你的内力不够500点。\n");        
	skill = (int)me->query_skill("zhenyuan-force",1);        
	if( skill < 100 )                     
        	return notify_fail("你的镇元神功等级不够100级。\n");        
	if( (int)me->query_skill("force",1) < 100 )                     
        	return notify_fail("你的内功心法等级不够100级。\n");        
	message_vision(HIY "$N"HIY"微一凝神，运起镇元神功，一股罡气从丹田直冲天顶。\n"NOR, me); 
	me->add("force", -300);
	time = skill/5; 
	skill = skill/10;
	me->add_temp("apply/combat_damage", skill);        
	me->add_temp("apply/spells_damage", skill);        
	me->set_temp("powerup", 1);        
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), time);        
	if( me->is_fighting() ) 
		me->start_busy(2);        
	return 1;
}

void remove_effect(object me, int amount)
{  
	if( me )
	{	
		me->add_temp("apply/combat_damage", -amount);        
		me->add_temp("apply/spells_damage", -amount);        
		me->delete_temp("powerup");
		message_vision(HIY "$N"HIY"将内力收回丹田。\n"NOR, me);
	}
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：三花聚顶
        内功所属：镇元神功
        内功效果：一定时间内增加自身的法术攻击、物理攻击
        	  不能叠加
        	  战斗中使用，自身busy 2 秒
        内功条件：
        	  人物等级 15 级
                  内力500点，消耗300点
                  镇元神功 100 级
                  基本内功 100 级
                  
STR;
        me->start_more(str);
        return 1;
}
