// bibo.c// Modify by Jingxue for XYCQ 2.11.2004
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

mapping action = ([
        "action"        : HIW"只见$N"HIW"抡起手中的$w"HIW"，使出「"HIY"神龙出水"HIW"」万点金光洒向$n"HIW"。\n"NOR,
        "dodge"         : -35,
        "parry"         : -35,
        "damage"        : 100,
        "damage_type"   : "戳伤",
]);
 
int perform(object me, object target)
{
	object weapon;
        
        if( me->query_level()<10 )
        	return notify_fail("你的人物等级不够。\n");
	if((int)me->query("force") < 300 )
        	return notify_fail("你体内的内力不足300点！\n");        
	if((int)me->query_skill("fengbo-cha",1) < 100)
        	return notify_fail("你的『风波十二叉』等级不够！\n");
	if((int)me->query_skill("fork",1) < 100)
        	return notify_fail("你的『基本叉法』等级不够！\n");
	if( time()<me->query_temp("sea_bibo")+5 )
		return notify_fail("你掀不起更多的风浪了。\n");
		        	
        weapon = me->query_temp("weapon");
	if( !weapon
	 || ( weapon->query("skill_type")!="fork"
	   && weapon->query("use_apply_skill")!="fork" ) )
		return notify_fail("你手里没叉，掀不起风浪。\n");
	if( !target ) target = offensive_target(me);
	if( !target
 	 || !target->is_character()        
 	 || target->is_corpse()
 	 || target==me
 	 || !me->is_fighting(target) )
		return notify_fail("你要对谁施展这一招『碧波浪涌』？\n");

	message_vision(HIG"\n$N"HIG"作龙吟之声，踏碧波而来，$n"HIG"只看到$N"HIG"化做数团身影，漫天叉影席卷而来！\n"NOR, me, target);
	me->add("force", -100);
	me->set_temp("sea_bibo",time());
	me->set_temp("pfm_color","HIG");
	me->set_temp("PERFORM_BIBO",9);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
	me->set_temp("PERFORM_BIBO",10);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
	me->set_temp("PERFORM_BIBO",11);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
	
	if( me->query("family/family_name")=="东海龙宫"
	 && me->query_skill("fengbo-cha",1)>200 )
	{
		me->set_temp("PERFORM_BIBO",12);
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);		
	}
	me->delete_temp("pfm_color");
	me->delete_temp("PERFORM_BIBO");

	if( me->query("family/family_name")=="东海龙宫"
	 && me->query_skill("fengbo-cha",1)>300 )
	{
		me->set("actions",action);
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);		
	}		 
	me->reset_action();	
	return 1;
}

int help(object me)
{
string str;
if ( !me )      return 0;
str = @LONG
        外功名称：碧波浪涌
        外功所属：风波十二叉
        外功效果：视技能等级连续攻击对方3-5次
                  非龙宫弟子最多只能攻击3次
                  冷却时间 5 秒
        外功条件：
                  人物等级10级
                  内力300点，消耗100点
                  风波十二叉100级
                  基本叉法100级
                  
LONG;
me->start_more(str);
return 1;
}

