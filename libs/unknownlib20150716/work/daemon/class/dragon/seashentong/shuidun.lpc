#include <ansi.h>
inherit SSERVER;

int valid_cast(object me)
{
	int t = me->query_skill("jiefeng",1);
	if(me->query("family/family_name") != "东海龙宫")
        	return notify_fail("这是东海龙宫不传之密！\n");
	if( me->query_level()<5 )
		return notify_fail("你的人物等级不够。\n");        
        if( (int)me->query("mana") < 100 )
                return notify_fail("你的法力不够了！\n");
	t = 60-t/30;
	if( t>3 )
		t = 3;
	if( time()<me->query_temp("last_huicheng")+t )                
		return notify_fail("你刚刚水遁过。\n");
	return 1;
}	

int cast(object me, object target)
{       
        object soldier;

	if( !valid_cast(me) || me->is_fighting() )
		return 0;
	if( me->is_no_move() )
		return notify_fail("你现在动弹不得。\n");
	if( environment(me)->query("no_huicheng") )
		return notify_fail("这里不能使用回城技能。\n");
					
        message_vision("$N喃喃地念了几句咒语。\n", me);
        me->add("mana", -50);

        if( random(me->query("max_mana")) < 20 ) {
                message("vision", "但是什么也没有发生。\n",environment(me));
                return 1;
        }
	message_vision(HIG"\n$N"HIG"的脚下突然涌起一股水波，水流过后，$N"HIG"随之不见了！\n"NOR, me);
	me->set_temp("last_huicheng",time());
        me->move("/d/sea/yujie2",2);
        message("vision",HIG"\n突然一阵水波涌起，"+me->name()+HIC"从中走了出来。。。\n"NOR,environment(me),({me}));
        tell_object(me,HIC"\n你借水遁回到了师门。\n"NOR);
        return 3;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：水遁术
        法术所属：碧海神通
        法术效果：返回师门
        	  战斗中不能使用
        	  冷却时间30秒
        法术条件：
                  东海龙宫弟子
        	  人物等级5级
                  法力100点，消耗50点
                  
STR;
        me->start_more(str);
        return 1;
}