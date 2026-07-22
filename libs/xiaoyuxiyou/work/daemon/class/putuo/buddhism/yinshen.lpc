// yinshen.c 隐身术

inherit SSERVER;
#include <ansi.h>

int cast(object me)
{
	int howlong;
	int spell;
	
	if( me->query_level()<40 )
		return notify_fail("你的人物等级不够。\n");
	spell = me->query_skill("buddhism",1);
	if(spell<300)
		return notify_fail("你的大乘佛法不够精深。\n");
    	if(me->query("family/family_name")!="南海普陀山")
    		return notify_fail("不是佛门弟子不能用「隐身法」！\n");
	if( (int)me->query("mana") < 800 )
		return notify_fail("你的法力不够了！\n");
	if( (int)me->query("sen") < 50 )
		return notify_fail("你的精神无法集中！\n");
	if( me->is_yinshen() )
		return notify_fail("你已经处于隐身状态了。\n");
	if( me->is_fighting() )
		return notify_fail("战斗中不能使用隐身。\n");
			
	message_vision("$N喃喃地念了几句咒语。\n", me);
	if( random(me->query_maxmana()) < 200 ) 
	{
		me->add("mana",-100);
		me->receive_damage("sen",10);
		message("vision", "但是什么也没有发生。\n", environment(me));
		return 5;
	}
	me->add("mana", -200);
	me->receive_damage("sen", 30);
	howlong = 15 + random((me->query_skill("spells") -100));
	message_vision(HIW"\n只见一道白光闪过，$N"HIW"踪迹皆无。\n\n"NOR, me);
	me->start_yinshen(howlong);
	return 2;
}

int help(object me)
{
string str;
if ( !me )  return 0;
str = @LONG
        法术名称：隐身咒
        法术所属：大乘佛法
        法术效果：隐匿自己的行踪，使四周生物无法察觉自己
                  能潜入有守护的房间
                  进入战斗状态失效
                  战斗中不能使用
                  如果敌人也处于隐身状态，则能发现自己
                  需要领悟
        法术要求：
        	  普陀弟子
        	  人物等级40级
                  法力800点，消耗200点
                  精神 50 点，消耗 30 点
                  大乘佛法 300 级
LONG;
me->start_more(str);
return 1;
}
