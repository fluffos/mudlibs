//Cracked by Roath
//
#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
	if( me->query_level()<5 )
		return notify_fail("你的人物等级不够。\n");
        if( (int)me->query("mana") < 600 )
		return notify_fail("你的法力不够了！\n");
        if( (int)me->query("sen") < 50 )
                return notify_fail("你的精神无法集中！\n");
	if((string)me->query("family/family_name")!="阎罗地府" )
		return notify_fail("你试着将自己化为气体，可血肉之躯却怎么也化不开！\n");
	if( me->is_fighting() )
		return notify_fail("你现在正在战斗呢。\n");
	if( me->is_no_move() )
		return notify_fail("你现在动弹不得。\n");
	if( environment(me)->query("no_huicheng") )
		return notify_fail("这里不能使用回城诀。\n");
	if( time()<me->query_temp("last_huicheng")+30 )
		return notify_fail("你刚刚将血肉之躯化作阴风。\n");
					
        message_vision("$N喃喃地念了几句咒语。\n", me);
	me->add("mana", -50);
	me->receive_damage("sen", 20);

	message_vision(HIB"$N"HIB"口中喷出一股黑风，整个人也随着黑风散去。。。\n"NOR, me);
	me->set_temp("last_huicheng",time());
	me->move("/d/death/gate");
	message("vision",HIB"\n一阵阴风过后，隐约现出"+me->name()+HIB"的影子。\n\n"NOR,environment(me),me);
	me->start_busy(1);
        return 1;
}

int help(object me)
{
	string str;
	if( !me )      
		return 0;
str = @LONG
        法术名称：回城术
        法术所属：勾魂术
        法术效果：返回门派
                  自身busy 1 秒 
                  冷却30秒
        法术条件：
        	  人物等级5级
        	  地府弟子	
                  精神50点，消耗20点
                  法力600点，消耗50点 

LONG;
	me->start_more(str);
	return 1;
} 