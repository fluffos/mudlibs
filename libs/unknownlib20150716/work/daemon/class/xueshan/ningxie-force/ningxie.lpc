//ningxie-force凝血大法
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target)
{
	int damage,p;
	string msg,succ_msg;
        
        if(me->query("family/family_name")!="大雪山") 
        	return notify_fail("冰谷凝血功只有雪山弟子才可以用！\n");
        if( me->query_level()<15 )
        	return notify_fail("你的人物等级不够。\n");
        if( (int)me->query("force") < 500 )
                return notify_fail("你的真气不够。\n");
	if( me->query("kee")<300 )
		return notify_fail("你气血不足，无法催动寒气。\n");                
	if( me->query_skill("ningxie-force",1)<100 )
		return notify_fail("你的【冰谷凝血功】火候太浅，用不出“凝血大法”！\n");
	if( time()<me->query_temp("force_ningxue")+5 )
		return notify_fail("你刚刚催动过寒气。\n");
			
	if( !target ) 
        	target = offensive_target(me);
         if( !target || !target->is_character()
          || target==me || target->is_corpse() 
	  || !me->is_fighting(target) )        	
                return notify_fail("只能在战斗中对敌人使用！\n");
                
	msg = HIW"$N"HIW"脸色一寒，浑身发出冰雪般的寒气，铺天盖地卷向$n"HIW"！。\n"NOR;
	succ_msg = WHT"$n"WHT"躲闪不及，被寒气裹个正着，全身都冻僵了！\n"NOR;
	me->add("force",-150);
	p = me->query_skill("force")/10;
	me->add_temp("apply/attack",p);
	me->receive_damage("kee",200,me);
	me->set_temp("force_ningxue",time());
	me->set_temp("pfm_msg",1);
	me->set_temp("pfm_color",WHT);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg,0,me->query_skill("force")/30);
	me->add_temp("apply/attack",-p);
	me->delete_temp("pfm_msg");
	me->delete_temp("pfm_color");
	
	if( damage>0 )
	{
		if( !target->is_busy() )
			target->start_busy(3);
		else	target->start_busy((int)target->query_busy()+random(2)+1);
	}		
	else
	{
        	message_combatd(HIC"$N"HIC"觉出危险，身行急退，躲开了此式！\n"NOR,target);
		me->add("force", -100);
		if( me->query("force")<0 )
			me->set("force",0);
		me->add_temp("force_ningxue",2);
	}	
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：凝血大法
        内功所属：冰谷凝血功
        内功效果：运转冰谷凝血功用寒气击敌
        	  命中则使对方busy，否则自身内气消耗增加100点
        	  冷却时间5秒，未命中，冷却时间增加2秒
        内功条件：
        	  雪山弟子	
        	  人物等级 15 级
                  内力500点，消耗150点
                  气血300点，消耗200点
                  冰谷凝血功100级
STR;
        me->start_more(str);
        return 1;
}

