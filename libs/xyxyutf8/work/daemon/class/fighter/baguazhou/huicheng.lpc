#include <ansi.h>
inherit SSERVER;

int valid_cast(object me)
{
	if(me->query("family/family_name") != "将军府")
        	return notify_fail("这是将军府不传之密！\n");
	if( me->query_level()<5 )
		return notify_fail("你的人物等级不够。\n");        
        if( (int)me->query("mana") < 100 )
                return notify_fail("你的法力不够了！\n");
	if( me->query("kee")<100 )
		return notify_fail("你现在气血不足，画不了符。\n");                
	if( time()<me->query_temp("last_huicheng")+30 )
		return notify_fail("你刚刚画过回城符。\n");
	return 1;
}	

int cast(object me, object target)
{       
        object seal;

	if( !valid_cast(me) )
		return 0;
	if( me->is_no_move() )
		return notify_fail("你现在动弹不得。\n");
	if( environment(me)->query("no_huicheng") )
		return notify_fail("这里不能使用回城诀。\n");
	seal = present("paper seal",me);
	if( !seal || base_name(seal)!="/obj/paper_seal" )
		return notify_fail("你身上没有桃符纸，如何画符？\n");
						
        message_vision("$N咬破手指，伸手在桃符纸上画了几下。\n", me);
        me->add("mana", -80);
	me->receive_damage("kee",50,me);
	if( me->is_fighting() )
		me->start_busy(2);
	message_vision(HIR"$N"HIR"大喊一声“着”，手一挥，祭出了一张回城符。。。\n\n"NOR);
	tell_room(environment(me),"周围呼的一下闪出一片火光。\n");
	if( random( (int)me->query_kar()+ (int)me->query_cps()) > 10 )	
	{
		tell_room(environment(me),"\n"+me->name()+"趁着火影逃跑了。\n");
		me->move("/d/jjf/se_garden");
		tell_object(me,HIC"\n你借桃符之力回到了师门。\n"NOR);
	}
	else 	tell_room(environment(me), "\n谁知火势太猛，"+me->name()+"没跑掉。\n");
	if( seal->query_amount()<2 )
		destruct(seal);
	else	seal->add_amount(-1);	
        return 3;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：回城符
        法术所属：八卦咒
        法术效果：返回师门
        	  战斗中使用busy 2 秒
        	  冷却30秒
        法术条件：
                  将军府弟子
        	  人物等级5级
        	  需要桃符纸
                  法力100点，消耗80点
                  气血100点，消耗50点
                  
STR;
        me->start_more(str);
        return 1;
}