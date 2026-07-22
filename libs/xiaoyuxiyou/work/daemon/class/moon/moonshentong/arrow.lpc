// arrow.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int valid_cast(object me)
{
	if( me->query_level()<40 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query("mana")<800 )
		return notify_fail("法力不足。\n");	
	if((int)me->query("sen") < 100 )
		return notify_fail("你无法集中精力瞄准！\n");
	if( me->query_skill("moonshentong",1)<400 )
		return notify_fail("你的月宫仙法等级不够。\n");
	return 1;		
}

int cast(object me, object target)
{
	int damage,base_damage;
	string msg,succ_msg;

	if( !valid_cast(me) )
		return 0;	
	
	if( !target ) target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me
	|| !me->is_fighting(target) )
		return notify_fail("你要对谁施展落日神箭？\n");

	if( time()<me->query_temp("moon_arrow")+5 )
		return notify_fail("绝招用多就不灵了。\n");
				
	me->add("mana", -150);
	me->receive_damage("sen",50);
	me->set_temp("moon_arrow",time());
	if( random(me->query_maxmana()) < 50 ) 
	{
		write("后羿正跟老婆赌气，来不了了！\n");
		me->add_temp("moon_arrow",2);
		return 1;
	}

	msg = HIC "$N"HIC"口中念了几句咒文，随着一声“后羿在此！”半空中现出一位身披虎皮的大汉。只见他张弓搭箭，“嗖”的一声，一只蓝汪汪的长箭向$n"HIC"$l激射而去！\n" NOR;
	succ_msg = HIR"结果长箭从$n"HIR"$l直透而过，顿时血花飞溅！\n" NOR;
	base_damage = (int)me->query_skill("moonshentong",1)/50;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg,0,base_damage,"both");
	me->set_temp("pfm_msg",0);
	if( damage<=0 )
	{
		message_vision(HIC "只见$N"HIC"轻轻一跳，长箭正好插在$P脚边，兀自颤动不休！\n" NOR,target);
		me->add("mana",-50);
	}
	else
	{
		if( damage>=5 )
		{
			target->receive_wound("kee",damage/5,me,TYPE_CAST);
			COMBAT_D->report_status(target,1);
		}	
		target->receive_damage("kee",damage,me,TYPE_CAST);
		COMBAT_D->report_status(target);
		if( damage>=5 )
			target->receive_wound("sen",damage/5,me,TYPE_CAST);
	}		
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：落日神箭
        法术所属：月宫仙法
        法术效果：召唤后羿异象对敌进行法术攻击
		  法力太低会可能召唤失败
		  冷却5秒
        法术条件：
                  月宫弟子
        	  人物等级40级
                  法力800点，消耗150点，
                  精神100点，消耗50点
                  月宫仙法 400 级
                  
STR;
        me->start_more(str);
        return 1;
}