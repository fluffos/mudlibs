#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg,limb,str; 
        int damage,succ;

	if( me->query_skill("xuehejue",2)>=1 )
		return notify_fail("你既然已经学了血河诀，就不能三心二意。\n");
        if( !target ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || target->is_corpse()
         || target->is_ghost()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你要对谁施展「四屏化力」。\n");
	if( time()-(int)me->query_temp("pingfeng_hua") < 6 )
        	return notify_fail("绝招用多就不灵了！\n");
        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足。\n");
        if((int)me->query_skill("pingfeng",1) < 100)
                return notify_fail("你的「屏风四扇门」火候还不到，使用这一招会有困难！\n");
	
	message_vision(HIY"$N"HIY"面色一沉，眉心隐现金石之气，双掌挥动间略带铿锵之声。\n"NOR,me);
	me->set_temp("pingfeng_hua",time());
	me->add("force",-150);
	message_combatd(HIY"$N"HIY"周身忽发石门大开般巨响，背后隐现四道图案古朴的石屏，随之一掌遥遥击向$n"HIY"！\n"NOR,me,target);
	
	succ = COMBAT_D->attack_percent(me,target,TYPE_PERFORM);
	if( succ<=0 )
	{
		message_combatd(HIC"\n$n"HIC"身形一晃，躲过了$N"HIC"的攻击。\n"NOR,me,target);
		me->start_busy(3);
		return 1;
	}
	msg = HIR"$n"HIR"脸色一变，脚下踉跄几步，呕出几口鲜血，";
	str = "";
	if( me->query_skill("pingfeng",1)>=100 )
	{
		limb = "只见$p"+({"左","右"})[random(2)]+"肋出现了触目惊心的掌印！\n"NOR;
		damage = COMBAT_D->valid_damage(me,target,"pingfeng",TYPE_PERFORM);
		if( damage<100 )
			damage  = 100;
		target->receive_wound("kee",damage,me,TYPE_PERFORM);
		str+= ({
			HIR"结果这一下「砰」地一声打得$n"HIR"连退了好几步，差一点摔倒！\n"NOR,
        		HIR"结果重重地击中，$n"HIR"「哇」地一声吐出一口鲜血！\n"NOR,
        		HIR"结果只听见「砰」地一声巨响，$n"HIR"像一捆稻草般飞了出去！\n"NOR,
        	})[random(3)];
	}
	if( me->query_skill("pingfeng",1)>=200 )	
	{
		limb = "只见$p左右两肋出现了触目惊心的掌印！\n"NOR;
		damage = COMBAT_D->valid_damage(me,target,"pingfeng",TYPE_PERFORM);
		if( damage<100 )
			damage  = 100;
		target->receive_wound("sen",damage,me,TYPE_PERFORM);
		str+= ({
        		HIR"结果$n"HIR"痛哼一声，脸色有少许发白。\n"NOR,
        		HIR"结果$n"HIR"只觉心神一阵震荡，脸色顿时变得有些青白！\n"NOR,
        		HIR"结果$n"HIR"闷哼了一声，脸上一阵青一阵白，精神好似有些萎靡！\n"NOR,
        		HIR"结果$n"HIR"脸色一下变得惨白，疼痛直达元神深处！\n",
        		HIR"结果$n"HIR"一声惨叫，脸色一片惨白，三魂七魄好似要突体而去！\n"NOR,
        		HIR"结果只听见$n"HIR"一声惨叫，脸色全无人样，三魂七魄好似散了一般，整个人顿时浑浑噩噩！\n"NOR,
        	})[random(6)];
	}	
	if( me->query_skill("pingfeng",1)>=300 )	
	{
		limb = "只见$p胸口、左右两肋出现了触目惊心的掌印！\n"NOR;
		if( target->query("mana")>0 )
		{
			damage = me->query_skill("unarmed")/2;
			damage = damage/5+random(damage/2);
			if( target->query("mana")<damage )
				target->set("mana",0);
			else	target->add("mana",-damage);
			str+= HIR"结果"HIR"$n"HIR"只觉精神一阵萎靡，法力不住外泄！\n"NOR;
		}
	}
	if( me->query_skill("pingfeng",1)>=400 )
	{
		limb = "只见$p胸口、腹部、左右两肋出现了触目惊心的掌印！\n"NOR;
		if( target->query("force")>0 )
		{
			damage = me->query_skill("unarmed")/2;
			damage = damage/5+random(damage/2);
			if( target->query("force")<damage )
				target->set("force",0);
			else	target->add("force",-damage);
			str+= HIR"结果"HIR"$n"HIR"只觉内息紊乱，内力不住外泄！\n"NOR;
		}
	}
	msg = msg+limb+str;
	message_combatd(msg,me,target);
	if( me->query_skill("pingfeng",1)>=200 )
		COMBAT_D->report_sen_status(target);
	COMBAT_D->report_status(target,1);
 	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：四屏化力
        外功所属：屏风四扇门
        外功效果：屏风四扇门每100级依次化去对方的气血、精神、内力、法力
        	  冷却时间 6 秒	
        	  失败自身busy 3 秒
        外功条件：
                  内力500点，消耗150点
                  内功心法 100 级
                  屏风四扇门 100 级
STR;
        me->start_more(str);
        return 1;
}   
