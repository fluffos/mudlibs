//zhanqi by yushu 2001.2
#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int skill)
{
	if(!me) return;
        me->add_temp("apply/combat_damage",-skill);
        me->add_temp("apply/spells_damage",-skill);
    	me->delete_temp("shushan_zhanqi");
	tell_object(me, HIM"你的天罡战气循环一周天完毕，将内力收回丹田。\n"NOR);
}

int exert(object me, object target)
{
	int skill;
	
	if( me->query_level()<40 )
		return notify_fail("你的人物等级不够。\n");
	if( !target ) target = me;		
	if( target != me ) 
		return notify_fail("你只能对自己使用。\n");
	if(me->query("family/family_name")!="蜀山派")
      		return notify_fail("你不是蜀山弟子，不能使用这项技能！\n");
	if( (int)me->query("force") <500 )     
		return notify_fail("你的内力不够。\n");
	if( me->query_skill("xianfeng-yunti",1)<400 )
		return notify_fail("你的仙风云体术不够娴熟。\n");		
        if( (int)me->query_temp("shushan_zhanqi") ) 
		return notify_fail("你已经在运功中了。\n");

        me->add("force", -200);
	skill = me->query_skill("force");
	skill = skill/2;
	
        message_vision(HIM "$N"HIM"微一凝神，运起仙风云体术，一股天罡战气从丹田直冲天顶。\n" NOR, me);
        me->add_temp("apply/combat_damage",skill);
        me->add_temp("apply/spells_damage",skill);
	me->set_temp("shushan_zhanqi", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :),me->query_skill("force"));
	if( me->is_fighting() ) me->start_busy(2);
        return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        内功名称：天罡战气
        内功所属：仙风云体术
        内功效果：一定时间内增加自身的物理与法术伤害
                  战斗中使用自身busy 2 秒
        内功条件：
                  蜀山派弟子
        	  人物等级40级	
                  内力500点，消耗200点
                  仙风云体术400级
LONG;
me->start_more(str);
return 1;
} 