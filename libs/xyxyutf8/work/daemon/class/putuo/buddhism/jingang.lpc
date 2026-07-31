#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int cast(object me,object target)
{
	int skill;
	
	if( me->query_level()<45 )
		return notify_fail("你的人物等级不够。\n");	
	if( (int)me->query_skill("buddhism", 1) < 450 )
        	return notify_fail("你的大乘佛法等级不够。\n");
	if(me->query("bonze/class")!="bonze" ) 
		return notify_fail("不是佛门弟子不能用「金刚咒」！\n");
	if( (int)me->query("mana") < 500 )     
        	return notify_fail("你的法力不够。\n");
        if( me->query_temp("powerup") )
        	return notify_fail("你现在不能施展金刚咒。\n");	
        	
	message_vision(HIW"$N"HIW"微一凝神，念动咒语，"NOR,me);
	message_combatd(HIY"只见$N"HIY"隐现一尊丈八金刚，不怒而威，凌空在$P顶梁一抹，一道金光闪过，$N"HIY"周身顿时绽放万道金光，宛如神灵，叫人不禁垂首膜拜。\n"NOR,me);
	me->add("mana", -200);		
	skill = me->query_skill("spells");      
	me->set_temp("powerup",1);
	me->add_temp("apply/max_kee",10000);
	me->add_temp("apply/max_sen",10000);
	me->receive_curing("kee",10000);
	me->receive_curing("sen",10000);
	me->receive_heal("kee",10000);
	me->receive_heal("sen",10000);
	me->start_call_out( (: call_other, __FILE__, "remove_effect",me :), skill); 
	return 1;
}

void remove_effect(object me, int amount)
{
	if( me )
	{
		me->delete_temp("powerup");
		me->add_temp("apply/max_kee",-10000);
		me->add_temp("apply/max_sen",-10000);
		me->receive_curing("kee",1);
		me->receive_curing("sen",1);
		me->receive_heal("kee",1);
		me->receive_heal("sen",1);
		message_combatd(HIY"$W"HIY"身上的金光渐渐隐去了。\n"NOR,me);
	}	
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        法术名称：金刚咒
        法术所属：大乘佛法
        法术效果：一定时间内提升自身的最大气血、精神各10000点
        法术条件：
                  佛门弟子
                  人物等级45级	
                  法力500点，消耗200点
                  大乘佛法450级
LONG;
me->start_more(str);
return 1;
}
