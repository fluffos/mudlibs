// 回梦
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int valid_cast(object me)
{
	if( me->query_level()<45 )
		return notify_fail("你的人物等级不够。\n");
	if( (int)me->query_skill("moonshentong",1) < 350 )
		return notify_fail("你的月宫仙法等级过低。\n");
	if( !me->is_knowing("moon_huimeng") )		
		return notify_fail("你还没学会回梦咒。。。\n");
	if( me->query("family/family_name")!="月宫" 
	 && me->query("chushi/chushi_moon")!="yes" )
		return notify_fail("你不能使用这项技能！\n");
	if((int)me->query("mana") < 800 )
		return notify_fail("你的法力不够！\n");
	if((int)me->query("sen") < 100 )
		return notify_fail("你无法集中精力！\n");	
	if( time()<me->query_temp("moon_huimeng")+10 )
		return notify_fail("绝招用多就不灵了。\n");			
	return 1;		
}

int cast(object me, object target)
{
	string msg;
	int success, ap, dp, howlong;
	int dayphase;
	
	if( !valid_cast(me) )
		return 0;
		
	if( !target ) target = offensive_target(me);
	if( !target
	 || !target->is_character()
	 || target->is_corpse()
	 || target==me)
		return notify_fail("你想咒谁入梦？\n");  
	if( !living(target) )
		return notify_fail("有这个必要吗？\n");
	if( COMBAT_D->check_level(me,target)==-1 )
		return notify_fail("对方境界高出你甚多，使用此招纯属自杀所为。\n");        	
		
  	me->add("mana", -200);
	me->receive_damage("sen", 50);
	me->set_temp("moon_huimeng",time());
	msg = HIM"$N"HIM"凝视着$n"HIM"的双眼，温柔地拍着$n的头，在$n耳边轻声唱着：“小宝宝，快睡觉。。。”$n"HIM"顿时觉得神倦眼困，全身无力。\n"NOR;

	dayphase =NATURE_D->query_current_day_phase();
	if (dayphase < 6)
		success = 2;
	else	success = 4;
	
	if( COMBAT_D->attack_percent(me,target,TYPE_CAST)>0 )
		success+= 5;
	else	success-= 2;	
	ap = me->query("mana");
	dp = target->query("mana");
	if( random(ap+dp)>=dp )
		success+= 3;
	else	success-= 1;	
	ap = me->query_per();
	dp = target->query_cps();
	if( random(ap+dp)>=dp )
		success+= 3;
	else	success-= 1;	
	
	if( random(success)>0 || COMBAT_D->check_level(me,target)==1 || me->query_temp("moon_huashen")=="hu" )
	{
		msg +=  HIM"$n"HIM"不知不觉的哈欠连连，眼皮沉重，终于支持不住，合上了双眼。\n"NOR;
            	message_vision(msg, me, target);
		target->set_temp("force_sleep",1);
   		if(target->is_fighting()) 
   			target->command_function("surrender");
		target->delete_temp("last_sleep");
		if(!target->command("sleep")) 
			message_vision(HIM"\n$N晃了晃脑袋，似乎清醒了不少，又把眼睛睁开了。\n"NOR,target);
		target->delete_temp("force_sleep");
		target->set_temp("last_sleep",time());
		me->start_busy(1+random(2)); 
	}	    
	else 
	{
		msg +=HIM"$n忽觉不妥，大喝一声，双目一张，精光四射！$N猝不及防，吓了一跳！\n" NOR;	
            	message_vision(msg, me, target);
            	if( living(target) && !target->is_killing(me->query("id")) )
            		target->kill_ob(me);
		me->start_busy(1+random(2)); 
	} 
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：回梦咒
        法术所属：月宫仙法
        法术效果：使对方进入睡眠状态(成功则必进入睡觉状态)
        	  冷却时间10秒
		  不能越阶使用
		  化狐状态下使用命中100%
		  需领悟
        法术条件：
                  月宫(出师)弟子
        	  人物等级45级
                  法力800点，消耗200点，
                  精神100点，消耗50点
                  月宫仙法 350 级
                  
STR;
        me->start_more(str);
        return 1;
}