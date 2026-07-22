#include <ansi.h>
#include "/cmds/std/valid_move.h"
inherit SSERVER;

int valid_cast(object me)
{
	int t = me->query_skill("tuxing",1);
	if(me->query("family/family_name") != "陷空山无底洞")
        	return notify_fail("这是无底洞不传之密！\n");
	if( me->query_level()<5 )
		return notify_fail("你的人物等级不够。\n");        
        if( (int)me->query("mana") < 100 )
                return notify_fail("你的法力不够了！\n");
	t = 60-t/30;
	if( t>3 )
		t = 3;
	if( time()<me->query_temp("last_huicheng")+t )
		return notify_fail("你刚刚刨过土。\n");
	return 1;
}	

int cast(object me, object target)
{       
        object soldier;

	if( !valid_cast(me) || me->is_fighting() )
		return 0;
	if( !valid_move(me) )
		return notify_fail("你现在动弹不得。\n");
	if( environment(me)->query("no_huicheng") )
		return notify_fail("这里不能使用回城诀。\n");
					
        message_vision("$N喃喃地念了几句咒语。\n", me);
        me->add("mana", -50);

        if( random(me->query("max_mana")) < 20 ) {
                message("vision", "但是什么也没有发生。\n",environment(me));
                return 1;
        }
	message_vision(YEL"$N"YEL"向空中抛了一把土，念句咒，钻入土中不见了。\n"NOR,me);
	me->set_temp("last_huicheng",time());
        me->move("/d/qujing/wudidong/kitchen",2);
        message("vision", YEL+me->name()+YEL"突然从地下钻了出来。\n"NOR,environment(me), me);
        tell_object(me,HIC"\n你借土遁之力回到了师门。\n"NOR);
        return 3;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：土遁术
        法术所属：妖法
        法术效果：返回师门
        	  战斗中不能使用
        法术条件：
                  无底洞弟子
        	  人物等级5级
                  法力100点，消耗50点
                  
STR;
        me->start_more(str);
        return 1;
}