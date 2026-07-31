// 蚀月咒?
inherit SSERVER;
#include <ansi.h>
#include <combat.h>

int valid_cast(object me)
{
	if( me->query_level()<25 )
		return notify_fail("你的人物等级不够。\n");
	if((int)me->query_skill("spells") < 200
	 || (int)me->query_skill("moonshentong",1) < 200 )
		return notify_fail("你法术修为不够。\n");
	if(me->query("family/family_name") != "月宫")
        	return notify_fail("「蚀月咒」是月宫不传之密！\n");
	if((int)me->query("mana") < 500 )
		return notify_fail("你的法力不够！\n");
	return 1;	
}

int cast(object me, object target)
{
	string msg;
	int success, ap, dp;
	int dayphase;

	if( !valid_cast(me) )
		return 0;	

	if( !target ) target = offensive_target(me);
	if( !target
	 || !target->is_character()
	 || target->is_corpse()
	 || target==me 
	 || !me->is_fighting(target) )
	 	return notify_fail("你想对谁施展蚀月咒？\n");  
	if( !me->is_killing(target->query("id")) )
		return notify_fail("不是生死相搏，还是不要用此招。\n");
	if( COMBAT_D->check_level(me,target)==-1 )
		return notify_fail("对方境界高出你甚多，使用此招纯属自杀所为。\n");        	
		 		
	dayphase =NATURE_D->query_current_day_phase();

        if( target->query_condition("moon_poison") )	
		return notify_fail(target->query("name")+"已经中邪了！\n");  
	if (dayphase < 6)
		success = 1;
	else	success = 3;	
	if( COMBAT_D->attack_percent(me,target,TYPE_CAST)>0 )
		success+= 3;
	else	success-= 2;	
	ap = me->query("mana");
	dp = target->query("mana");
	if( random(ap+dp)>=dp/2 )
		success+= 1;
	else	success-= 1;	
	
	me->add("mana", -100);
	msg = HIC
"$N"HIC"低头默默念起咒文，手中渐渐聚起一团光球，雪白的脸庞似乎发射出柔和的光芒。\n" NOR;

	if( random(success)>0 || COMBAT_D->check_level(me,target)==1 )
	{
		msg +=  HIR "$n"HIR"见到$N"HIR"祥宁之态，娇美不可方物，心中一荡，却不防那光球一闪，突然射向$n"HIR"。\n" NOR;
		target->apply_condition("moon_poison", ((int)me->query_skill("moonshentong",1)/20));
	}	    
	else 
	{
		msg +=  HIR "$N"HIR"脸色苍白，似乎体力不支，光球在手中渐渐褪去。！\n" NOR;	
		me->add("mana", -50);
	} 
	message_vision(msg, me, target);
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：蚀月咒
        法术所属：月宫仙法
        法术效果：使对方进入衰弱状态
        	  不能对已中蚀月的对象施展
                  不能越阶使用
		  夜晚使用，命中加倍
        法术条件：
                  月宫弟子
        	  人物等级25级
                  法力500点，消耗100点，失败则消耗150点
                  月宫仙法 200 级
                  基本法术 200 级
                  
STR;
        me->start_more(str);
        return 1;
}