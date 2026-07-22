// 步步生莲 lian.c
#include <ansi.h>
inherit SSERVER;
 inherit F_CLEAN_UP;
 
void remove_effect(object me, int p);

int valid_perform(object me)
{
        if( me->query_level()<15 )
        	return notify_fail("你的人物等级不够。\n");
        if( me->query_skill_mapped("dodge") != "lotusmove" )
		return notify_fail("你还没有施展莲花步呢。\n");
	if( me->query("family/family_name")!="南海普陀山" )
		return notify_fail("你不能使用这项技能！\n");
        if(me->query_skill("lotusmove",1)<120) 
        	return notify_fail("你的莲花步法还不够高明。\n");
        if(me->query_skill_mapped("force")!="lotusforce")
                return notify_fail("步步生莲必须配合莲台心法才能使用。\n");
        if(me->query_skill("lotusforce",1)<120) 
        	return notify_fail("你的莲台心法不够纯熟。\n");
        if( (int)me->query("force") < 100 )      
                return notify_fail("你的内力不够。\n");
	
	return 1;
}
 
int perform(object me, object target)
{
        int skill_sword, skill_dodge,p,t,extra1,extra2;
        
	if( !valid_perform(me) )
		return 0;
	        
	skill_dodge = me->query_skill("lotusmove",1);	
        skill_sword=me->query_skill("lotusforce",1);        
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");
        
        me->add("force", -50);
        message_vision(HIY"$N"HIW"运转莲台心法，顿时足下现出一品金莲，源源不断的念力冉冉升起，生生不息。\n" NOR, me);
        me->set_temp("powerup", 1);
        p = me->query_skill("lotusforce",1)/20;
        p+= me->query_skill("lotusmove",1)/20;
        p+= me->query_str()/5;
        p*= 10;
        t = me->query_skill("lotusmove",1);
        if( t>300 )
        	t = 300;
        
        me->add_temp("apply/max_kee",p);
	me->receive_curing("kee",p);
	me->receive_heal("kee",p);
        
        me->add_temp("apply/max_sen",p);
	me->receive_curing("sen",p);
	me->receive_heal("sen",p);
        
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, p:), t);
	return 1;
}
 
void remove_effect(object me, int p)
{
	if( me )
	{
	        me->add_temp("apply/max_kee",-p);
		me->receive_curing("kee",1);
		me->receive_heal("kee",1);
        
	        me->add_temp("apply/max_sen",-p);
		me->receive_curing("sen",1);
		me->receive_heal("sen",1);
		
        	me->delete_temp("powerup");
        	message_vision(HIW"白光一闪，$N"HIW"脚下的莲花化作点点光影，渐渐淡去。\n"NOR,me);
        }	
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：步步生莲
        外功所属：莲花步
        外功效果：一定时间内增加自身的气血与精神后限
                  不可与增益类状态叠加
        外功条件：
        	  普陀弟子
        	  人物等级15级
        	  基本轻功激发莲花步
        	  基本内功激发莲台心法
        	  内力100点，消耗50点
                  莲台心法等级 120 级
                  莲花步等级 120 级
STR;
        me->start_more(str);
        return 1;
}