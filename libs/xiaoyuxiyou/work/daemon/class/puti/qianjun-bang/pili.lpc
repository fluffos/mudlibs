// Pili.c 霹雳流星 
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg,str; 

	if( me->query_level()<15 )
		return notify_fail("你的人物等级不够。\n");
	
        if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me 
 	|| !me->is_fighting(target) )
		return notify_fail("你要对谁施展这一招「霹雳流星」？\n");
        
	if((int)me->query("max_force") < 1000 )
        	return notify_fail("你的内力不够！\n");
	if((int)me->query("force") < 600 )
        	return notify_fail("你的内力不足！\n");
	if((int)me->query("sen") < 300 )
        	return notify_fail("你的精神不足，没法子施用外功！\n");
	if((int)me->query_skill("qianjun-bang",1) < 100)
        	return notify_fail("你的千钧棒级别还不够，使用这一招会有困难！\n");
	if( time()-(int)me->query_temp("puti_pili") < 7 )
        	return notify_fail("绝招用多就不灵了！\n");

	message_vision(HIG"\n$N"HIG"运足精神，身形一转，霹雳间连续向$n"HIG"攻出了三招！\n"NOR,me,target);
	me->add("force",-150);
	me->receive_damage("sen", 100);
	me->set_temp("puti_pili",time());
	
	me->set_temp("QJB_perform", 4);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,30);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,50);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,80);
	return 1;
}

int help(object me)
{
	string str;
	if( !me )      
		return 0;
str = @LONG
        外功名称：霹雳流星
        外功所属：千钧棒
        外功效果：对敌进行三次带固定伤害的攻击
		  冷却时间 7 秒
        外功条件：
        	  人物等级15级
        	  千钧棒法100级	
                  内力600点，消耗150点
                  精神300点，消耗100点
LONG;
	me->start_more(str);
	return 1;
}