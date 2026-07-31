#include <ansi.h>
inherit SSERVER;

int valid_cast(object me)
{
	if(me->query("family/family_name") != "将军府")
        	return notify_fail("这是将军府不传之密！\n");
	if( me->query_level()<25 )
		return notify_fail("你的人物等级不够。\n");        
        if( (int)me->query("mana") < 500 )
                return notify_fail("你的法力不够了！\n");
	if( me->query("kee")<200 )
		return notify_fail("你现在气血不足，画不了符。\n");                
	if( time()<me->query_temp("jjf_peace")+60 )
		return notify_fail("你刚刚劝过降。\n");
	if( environment(me)->query("no_peace") )
		return notify_fail("这里不能使用休战诀。\n");	
	if( me->query_skill("baguazhou",1)<250 )
		return notify_fail("你的八卦咒等级不够。\n");	
		
	return 1;
}	

int cast(object me, object target)
{       
	int ap,dp;
        object seal;

	if( !valid_cast(me) )
		return 0;
	seal = present("paper seal",me);
	if( !seal || base_name(seal)!="/obj/paper_seal" )
		return notify_fail("你身上没有桃符纸，如何画符？\n");
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me
 	|| !me->is_fighting(target) )  
        	return notify_fail("你要对谁祭「休战符」？\n");	
        	
        message_vision("$N咬破手指，伸手在桃符纸上画了几下。\n", me);
        me->add("mana", -300);
	me->receive_damage("kee",150,me);
	me->set_temp("jjf_peace",time());
	if( me->is_fighting() )
		me->start_busy(2);
	message_vision(HIR"$N"HIR"大喊一声“着”，手一挥，祭出了一张休战符。。。\n\n"NOR);
	message_vision(HIC"休战符「呼」地一下飞到半空，$n"HIC"耳边隐隐传来“因果循环，报应不爽，众位还是得饶人处且饶人吧！”的声音。\n"NOR,me,target);
	if( seal->query_amount()<2 )
		destruct(seal);
	else	seal->add_amount(-1);	

	ap = (int)me->query_kar()+ (int)me->query_cps();
	dp = target->query("kar")+target->query("cps");
	
	if( random(ap+dp)<dp || COMBAT_D->check_level(me,target)==-1 )
	{
		message_vision(HIR"$n"HIR"朝$N"HIR"鄙夷一笑：米粒之珠，也放毫光？\n"NOR,me,target);
		me->start_busy(3);
		return 1;
	}	 
	message_vision(HIW"$n"HIW"听得，不由心中惭愧，停住了厮杀。。。。\n"NOR,me,target);
	target->remove_killer(me);
	me->remove_killer(target);
	return 5;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：休战符
        法术所属：八卦咒
        法术效果：使对方不再与自己战斗
                  失败则自身busy 3 秒 
                  冷却时间 60 秒
        法术条件：
                  将军府弟子
        	  人物等级25级
		  需要桃符纸
                  法力500点，消耗300点
                  气血200点，消耗150点
                  八卦咒250级
                  
STR;
        me->start_more(str);
        return 1;
}