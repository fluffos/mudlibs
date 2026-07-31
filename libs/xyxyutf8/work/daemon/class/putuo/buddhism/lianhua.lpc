#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int cast(object me,object target)
{
	int skill;
	
	if( !target )
		target = me;
	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");	
	if( !living(target) )
		return notify_fail("有这个必要吗？\n");	
	if( time()<me->query_temp("putuo_lianhua")+8 )
		return notify_fail("你刚刚禅唱过，还是先歇一歇。\n");		
	if( (int)me->query_skill("buddhism", 1) < 150 )
        	return notify_fail("你的大乘佛法等级不够。\n");
	if( me->query("family/family_name")!="南海普陀山" )
		return notify_fail("不是佛门弟子不能用「莲花宝座」！\n");
	if( (int)me->query("mana") < 500 )     
        	return notify_fail("你的法力不够。\n");
	if( me->query("kee")<200 || me->query("sen")<200 )
		return notify_fail("你现在状态不佳。\n");        
        if( target->query_temp("anti_magic") ) 
        	return notify_fail((me==target?"你":"对方")+"已经在运功中了。\n");
        
	if( target!=me )
		message_vision(HIW"$N"HIW"微一凝神，朝$n"HIW"一指，"NOR,me,target);
	else	message_vision(HIW"$N"HIW"微一凝神，念动咒语，"NOR,me);
	me->set_temp("putuo_lianhua",time());
	if( random(me->query("mana"))<100 )
	{
		message_vision(HIW"结果什么反应也没有。\n"NOR,me);
		me->add("mana", -50);
		me->add_temp("putuo_lianhua",-5);
		return 1;
	}
		
	skill = me->query_skill("spells");      
	me->add("mana", -80);
	me->receive_damage("kee", 100,me);
	me->receive_damage("sen", 100,me);
	message_vision(HIW"结果$N"HIW"背后幻出一朵白莲，五色毫光闪现。\n" NOR,target);
	
	target->set_temp("anti_magic", skill*2);
	target->add_temp("apply/combat_def",skill/5);
	target->add_temp("apply/spells_def",skill/5);
	target->add_temp("apply/re_spells_damage",skill/50);
	target->add_temp("apply/re_combat_damage",skill/50);	
	target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill :), skill); 
	if( me->is_fighting() ) 
		me->start_busy(2+random(2));
	return 1;
}

void remove_effect(object me, int amount)
{
	if( me )
	{
		me->set_temp("anti_magic", -amount*2);
		me->add_temp("apply/combat_def",-amount/5);
		me->add_temp("apply/spells_def",-amount/5);
		me->add_temp("apply/re_spells_damage",-amount/50);
		me->add_temp("apply/re_combat_damage",-amount/50);	
		message_combatd(HIW"$W"HIW"身后的白莲渐渐隐去了。\n"NOR,me);
	}	
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        法术名称：莲花宝座
        法术所属：大乘佛法
        法术效果：召唤莲花宝座,提高施法对象的物理与法术防御
                  同时提高施法对象的物理与法术伤害反弹几率
                  战斗中使用自身busy 2-3 秒
                  冷却8秒，失败则冷却增加5秒
        法术条件：
                  普陀弟子
                  人物等级20级	
                  法力500点，消耗80点，失败则消耗50点
                  气血200点，损耗100点
                  精神200点，损耗100点
                  大乘佛法150级
LONG;
me->start_more(str);
return 1;
}
