#include <ansi.h>

int exert(object me, object target, int amount)
{
        int force, lvl;
        
        if( !target )
        	target = me;
        if( !target->query_condition("ice_poison")
         && !target->query_condition("ice_suoxin") )
		return notify_fail((target==me?"你":"对方")+"又没有中寒毒。\n");
	if(me->query("family/family_name")!="大雪山" )
		return notify_fail("你不能使用这项技能！\n");
	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query_skill("ningxie-force",1)<200 )
		return notify_fail("你的冰谷凝血功火候太浅！\n");	
	if( me->query("force")<500 )
		return notify_fail("你的内息不纯。\n");
	if( me->query("kee")<500 )
		return notify_fail("你现在状态很差。\n");

	if( target->is_busy() 
	 || target->is_fighting() 
	 || !living(target) )
		return notify_fail("现在解毒恐怕会走火入魔。\n");
			 
	if( target==me )
	{
		me->add("force", -100  );
		me->receive_damage("kee",100,me);
                message_vision("$N运功抗毒，头上冒出豆大的汗．．．\n", me);
		me->start_busy(3);
	}
	else
	{
		me->add("force", -200  );
		me->receive_damage("kee",200,me);
                message_vision("$N将双掌抵住$n后背，助其运功抗毒，俩人头上冒出豆大的汗．．．\n", me,target);
		me->start_busy(3);
		target->start_busy(3);
	}		
	if( target->query_condition("ice_poison") )
	{
		target->apply_condition("ice_poison",0);
		message_vision(HIR"$N"HIR"”哇“的吐出一口冒着丝丝寒气血块，脸色顿时好了许多。\n"NOR,target);
	}
	if( target->query_condition("ice_suoxin") )
	{
		if( random(me->query("force"))<50 )
		{
			message_vision(HIR"$N"HIR"”哇“的吐出一口鲜血，脸色更加苍白。\n"NOR,target);
			write("完蛋！你内力不够，结果陷入了两难境地。\n");
			if( me!=target )
			{
				message_vision(HIR"$N"HIR"但觉$n"HIR"体内寒气如狂风般倒卷而来，顿时打了个冷战！\n"NOR,me,target);
				me->receive_wound("kee",150,me);
				COMBAT_D->report_status(me,1);
			}	
			else
			{
				target->receive_wound("kee",150,target);
				COMBAT_D->report_status(target,1);
			}	
		}
		else
		{
			target->apply_condition("ice_suoxin",0);
			message_vision(HIR"$N"HIR"”哇“的吐出一块冒着丝丝寒气腥臭血块，脸色顿时好了许多。\n"NOR,target);
		}	
	}		
	return 1;
}
 
int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：化冰诀
        内功所属：冰谷凝血功
        内功效果：运转冰谷凝血功逼除对象所中寒毒
        	  不能对战斗中的对象使用
        	  自身与对象均busy 3 秒
        内功条件：
        	  人物等级 20 级
        	  雪山弟子
        	  冰谷凝血功200级
        	  内力500点，消耗100点，对他人使用，消耗加倍
        	  气血500点，消耗100点，对他人使用，消耗加倍
STR;
        me->start_more(str);
        return 1;
}