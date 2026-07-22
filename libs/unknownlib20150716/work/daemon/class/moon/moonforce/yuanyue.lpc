// lifeheal.c
#include <ansi.h>

int valid_exert(object me)
{
	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");		
	if( (int)me->query("force") - (int)me->query("max_force") <  600 )
		return notify_fail("你的真气不够。\n");
	if((int)me->query_skill("moonforce",1)<100)
		return notify_fail("你的内功修为不足以替人解除蚀月咒。\n");
	return 1;	
}

int exert(object me, object target)
{
	if( !valid_exert(me) )
		return 0;	
	if( !target
         || !userp(target)
         || target->is_corpse()
         || target==me)
		return notify_fail("你想替谁解除蚀月咒？\n");
	if(!target->query_condition("moon_poison"))
        	return notify_fail("没中蚀月咒瞎搅和什么！\n");
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");
	if ((time()-target->query("last_sleep"))<90 )
		return notify_fail("对方刚刚休息过，不能治疗。\n");		
	message_vision(HIY "$N"HIY"盘膝念动真言，背后月轮旋转，$n"HIY"听$P语音清脆，越念越是冲和安静，全身隐隐发出圣洁的光辉。\n\n"NOR,me, target );
	me->add("force", -150);
    	if(random(me->query_skill("moonforce", 1)-60)>10)
    	{
		target->apply_condition("moon_poison",0);
		message_vision(HIY "$N背后太阴之轮越转越快，$n心中既感激，又安慰，在那越来越浓郁的月华之气中入了睡乡。\n"NOR,me, target );
		target->set_temp("force_sleep",1);
		target->command_function("sleep");
		target->delete_temp("force_sleep");	
	}
	else 	message_vision(HIY "$N"HIY"突然脸色苍白，似乎体力不支，竟呕出一口血来……\n"NOR,me, target );
 	target->receive_cuiring("kee", 10 + (int)me->query_skill("force")/3 );
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：圆月诀
        内功所属：圆月心法
        内功效果：运转圆月心法，利用太阴之气替对方治疗蚀月之咒，并治疗其气血。
        内功条件：
        	  人物等级 20 级
                  内力充沛，消耗150点
                  双方战斗中不可使用
STR;
        me->start_more(str);
        return 1;
}