#include <ansi.h>
#include <skill.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;     
	int time,damage;
	
	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me 
 	|| !me->is_fighting(target) )
        	return notify_fail("你要对谁使用无常爪？\n");
	if( me->query("family/family_name")!="阎罗地府"
 	&& me->query("chushi/chushi_hell")!="yes")
        	return notify_fail("你不能使用这项技能！\n");
	if((int)me->query("force") < 300 )
        	return notify_fail("你的内力不足！\n");
	if((int)me->query("sen") < 200 )
        	return notify_fail("你的精神不足，没法子施用外功！\n");
	if((int)me->query_skill("jinghun-zhang", 1) < 60)
        	return notify_fail("你的惊魂掌等级不够，不能使用这一招！\n");
	if( target->query_condition("hell_zhua") )
		return notify_fail("对方已经身陷无常索魂的境地。\n");
		
	message_vision(HIB"\n$N"HIB"口中默念几声：世事无常，死生无常……偏偏今天你"+target->name()+HIB"撞到我喜怒无常，你任命吧，看爪！\n"NOR,me,target);
	me->add("force",-100);
	me->receive_damage("sen",50,me);
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,HIG"$n"HIG"身子一晃，背上留下了一个惨绿色的爪痕！\n"NOR,0,me->query_skill("jinghun-zhang",1)/5);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
	{
		message_vision(HIY"$n"HIY"身子一闪，躲开了这一抓！\n"NOR,me,target);
		me->start_busy(5);
	}
	else
	{
		target->apply_condition("hell_zhua",10+me->query_skill("jinghun-zhang",1));
		me->start_busy(3);	
	}	
	return 1;
}

int help(object me)
{
string str;
if ( !me )      return 0;
str = @LONG
        外功名称：无常爪
        外功所属：惊 魂 掌
        外功效果：对敌攻击，命中则使对方身中索魂之苦
                  使后自身busy 3 秒，失败则自身busy 5 秒
        外功条件：
                  惊 魂 掌60级
                  内力300点，消耗100点
                  精神200点，消耗50点
               
LONG;
me->start_more(str);
return 1;
}


