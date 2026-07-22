//Cracked by Roath
//
#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
	if( me->query_level()<5 )
		return notify_fail("你的人物等级不够。\n");
        if( (int)me->query("mana") < 500 )
		return notify_fail("你的法力不够了！\n");
        if( (int)me->query("sen") < 50 )
                return notify_fail("你的精神无法集中！\n");
	if((string)me->query("family/family_name")!="方寸山三星洞" )
		return notify_fail("此乃方寸山秘法。\n");
	if( me->is_fighting() )
		return notify_fail("你现在正在战斗呢。\n");
	if( me->is_no_move() )
		return notify_fail("你现在动弹不得。\n");
	if( environment(me)->query("no_huicheng") )
		return notify_fail("这里不能使用回城诀。\n");
	if( time()<me->query_temp("last_huicheng")+60 )
		return notify_fail("你刚刚借用过乙木仙遁。\n");
									
	me->add("mana", -50);
	me->receive_damage("sen", 20);
	message_vision(HIG"$N"HIG"将身一摇，化作一道绿芒冲天而去。。。\n"NOR, me);
	me->set_temp("last_huicheng",time());
	me->move("/d/lingtai/gate");
	message("vision",HIG"\n一阵清风拂过，隐约现出"+me->name()+HIB"的影子。\n\n"NOR,environment(me),me);
	me->start_busy(1);
        return 1;
}

int help(object me)
{
	string str;
	if( !me )      
		return 0;
str = @LONG
        法术名称：乙木仙遁
        法术所属：道家仙法
        法术效果：返回门派
                  自身busy 1 秒 
        法术条件：
        	  人物等级5级
        	  方寸弟子	
                  精神50点，消耗20点
                  法力600点，消耗50点 

LONG;
	me->start_more(str);
	return 1;
} 