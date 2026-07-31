// 阴字诀 Yin.c
// Cracked by 凌惊雪 4-30-2003
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg,succ_msg;
	int damage,p=0;
	object tweapon;

	if( me->query_level()<8 )
		return notify_fail("你的人物等级不够。\n");
				
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me 
 	|| !me->is_fighting(target) )
		return notify_fail("「阴字诀」只能对战斗中的对手使用。\n");
		
	if( me->query_skill("liangyi-sword",1)<60 )	
		return notify_fail("你的「两仪剑法」还不够纯熟！\n");
        if((int)me->query("force") < 350 ) 
        	return notify_fail("你的内力不足！\n");
	if( userp(me) &&  me->is_knowing("puti_yinyang")!=1 )	
          	return notify_fail("你还不会这一招！\n");
	if( time()<me->query_temp("puti_yin")+6 )
		return notify_fail("你刚刚施展过。\n");
		
	msg = YEL"$N"YEL"一式「阴字诀」，剑走阴柔，手中$w"YEL"幻化阴极半鱼，朝向$n"YEL"缠去。\n"NOR;
	if(me->query("gender") != "女性")
	{
		p = 350-me->query_skill("liangyi-sword",1);
		if( p<=0 )
			p = 0;
	}
	if( p>0 )
		me->add_temp("apply/attack",-p);
	tweapon = target->query_temp("weapon");
	if( tweapon )
		succ_msg = YEL"结果$n"YEL"手中$W"YEL"被越缠越紧，一个把持不住，脱手而飞！\n" NOR;
	else
	{
		if( !target->is_busy() )
			succ_msg = YEL"结果$n"YEL"闪避不及，脚下打了个趔趄。\n"NOR;
		else	succ_msg = YEL"结果$n"YEL"被半鱼之气打了正着！\n"NOR;
	}
	me->set_temp("pfm_msg",1);	
	me->add("force",-50);
	me->set_temp("puti_yin",time());
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg);
	if( p>0 )
		me->add_temp("apply/attack",p);
	me->set_temp("pfm_msg",0);	
	if( damage<1 )
	{
		message_combatd(HIY"$n"HIY"不为所惑，凝神拆招，将半鱼之气打散，反将$N"HIY"打了措手不及！\n" NOR, me, target);		
		me->start_busy(1);
	}
	else
	{
		if( tweapon && tweapon=target->query_temp("weapon") )
		{
			tweapon->unequip();
			target->reset_action();
			if( !tweapon->query("changed") && !tweapon->query_autoload() )
				tweapon->move(environment(target));  
		}
		else if( !target->is_busy() )
			target->start_busy(3);	
	}
	return 1;
}

int help(object me)
{
	string str;
	if( !me )      
		return 0;
str = @LONG
        外功名称：阴字诀
        外功所属：两仪剑法
        外功效果：对敌一击，带打落对方兵器或使对方busy 3 秒特效
                  冷却时间6秒
                  男性使用，命中会降低 
                  需领悟
        外功条件：
        	  人物等级8级
        	  两仪剑法60级	
                  内力350点，消耗50点
LONG;
	me->start_more(str);
	return 1;
} 