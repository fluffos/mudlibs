// 阳字诀 Yang.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int damage,i,p=0;

	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
				
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me 
 	|| !me->is_fighting(target) )
		return notify_fail("「阴字诀」只能对战斗中的对手使用。\n");
		
	if( me->query_skill("liangyi-sword",1)<100 )	
		return notify_fail("你的「两仪剑法」还不够纯熟！\n");
        if((int)me->query("force") < 500 ) 
        	return notify_fail("你的内力不足！\n");
	if( userp(me) && !me->is_knowing("puti_yinyang")!=2 )	
          	return notify_fail("你还不会这一招！\n");
	
	msg = HIY"$N"HIY"闭目凝神，心如点转，一招充满太古剑意的阳极半鱼之气使出，看似平淡无奇，实则汇集了天地的元气，铺天盖地的压向$n"HIY"！\n" NOR;
	if(me->query("gender") != "男性")
	{
		p = 350-me->query_skill("liangyi-sword",1);
		if( p<=0 )
			p = 0;
	}
	if( p>0 )
		me->add_temp("apply/attack",-p);
	me->set_temp("pfm_msg",1);	
	me->add("force",-50);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,50);
	if( p>0 )
		me->add_temp("apply/attack",p);
	me->set_temp("pfm_msg",0);	
	i = (me->query_skill("liangyi-sword",1)-100)/50;
	if( i>3 )
		i = 3;
	while(i--)
	{
		if( !me || !living(me) || !target 
		 || !me->is_fighting(target)
		 || me->query("force")<30 )
		 	break;
		message_combatd(HIY"\n$N"HIY"剑意不绝，一招过后，又是一招！\n"NOR,me);
		me->add("force",-15);
		if( p>0 )
			me->add_temp("apply/attack",-p);
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
		if( p>0 )
			me->add_temp("apply/attack",p);
	}		 	
	if( time()<me->query_temp("puti_yin")+6 
	 && me->query_skill("liangyi-sword",1)>=350 
	 && me->query("force")>50 )
	{
		msg = HIG "\n$N手中$w"HIG"灵动异常，在剑意已尽之际，又生阴极半鱼，顿时太极之气蓬发，若狂风暴雨般扑向$n"HIG"！\n"NOR;
		me->set_temp("pfm_msg",1);	
		me->add("force",-50);
		damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
		me->set_temp("pfm_msg",0);
		if( damage>5 )
		{
			message_combatd(HIR"$n"HIR"只觉得阴阳二气袭体，眼睛顿时死鱼般的突了出来。。。。\n"NOR,me,target);
			target->receive_wound("kee",damage/5+1,me,TYPE_PERFORM);
			COMBAT_D->report_status(target,1);
		}
	}	 
	me->start_busy(1+random(2));	
	return 1;
}

int help(object me)
{
	string str;
	if( !me )      
		return 0;
str = @LONG
        外功名称：阳字诀
        外功所属：两仪剑法
        外功效果：对敌进行带固定伤害的一击，每50级追加一击
        	  有隐藏追击效果
                  女性使用，命中会降低 
                  自身busy 1-2 秒
                  需领悟
        外功条件：
        	  人物等级10级
        	  两仪剑法100级	
                  内力500点，消耗50点，每追加一击，消耗增加25点
LONG;
	me->start_more(str);
	return 1;
} 