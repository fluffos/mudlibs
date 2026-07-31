#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;     
	int time,damage;
	
	if( me->query_level()<15 )
		return notify_fail("你的人物等级不够。\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me 
 	|| !me->is_fighting(target) )
        	return notify_fail("你要对谁使用「历鬼三哭」？\n");
	if( me->query_skill_mapped("unarmed")!="jinghun-zhang" )
		return notify_fail("你的必须使用惊魂掌。\n");        	
	if((int)me->query("force") < 800 )
        	return notify_fail("你的内力不足！\n");
	if((int)me->query("sen") < 200 )
        	return notify_fail("你的精神不足，没法子施用外功！\n");
	if((int)me->query_skill("jinghun-zhang", 1) < 120)
        	return notify_fail("你的惊魂掌等级不够，不能使用这一招！\n");
	if( time()<me->query_temp("hell_ku")+5 )
		return notify_fail("你刚刚施过，还是歇歇再说。\n");
	
	me->set_temp("hell_ku",time());
	me->add("force",-100);
	me->receive_damage("sen",40,me);
	msg = HIR"$N"HIR"一声阴森渗人的长哭，双臂挥舞间，一股漫天血气冲向了$n"HIR"$l！\n"NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
	
	msg = HIR"\n紧接着$N"HIR"扬天一声嘶嚎，但见一道冲天的血气直冲$n"HIR"！\n"NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
	
	msg = HIR"\n$N"HIR"又是一声悲哭，双掌顿时映出糁人的血光，狠狠拍向$n"HIR"！\n"NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,(int)me->query_skill("unarmed")/10);
			
	return 1;
}

int help(object me)
{
string str;
if ( !me )      return 0;
str = @LONG
        外功名称：历鬼三哭
        外功所属：惊 魂 掌
        外功效果：对敌连续三次攻击
                  冷却时间 5 秒
        外功条件：
        	  人物等级15级
                  惊 魂 掌1200级
                  内力800点，消耗100点
                  精神200点，消耗40点
               
LONG;
me->start_more(str);
return 1;
}


