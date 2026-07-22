//双鱼诀 
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg,succ_msg;
	int damage,i;
	object weapon,tweapon;

	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
				
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me 
 	|| !me->is_fighting(target) )
		return notify_fail("「双鱼诀」只能对战斗中的对手使用。\n");
		
	if( me->query_skill("liangyi-sword",1)<200 )	
		return notify_fail("你的「两仪剑法」还不够纯熟！\n");
	if( me->query_skill("sword",1)<200 )
		return notify_fail("你的剑法底子太差！\n");
        if((int)me->query("force") < 500 ) 
        	return notify_fail("你的内力不足！\n");
	weapon = me->query_temp("weapon");
        if( !weapon
	 || ( weapon->query("skill_type")!="sword"
	   && weapon->query("use_apply_skill")!="sword" ) )
                return notify_fail("你必须在使用兵器时才能使「双鱼诀」！\n");          	
		
	msg = YEL"$N"YEL"一式「阴字诀」，剑走阴柔，手中$w"YEL"幻化阴极半鱼，朝向$n"YEL"缠去。\n"NOR;
	tweapon = target->query_temp("weapon");
	if( tweapon )
		succ_msg = YEL"\n结果$n"YEL"手中$W"YEL"被越缠越紧，一个把持不住，脱手而飞！\n" NOR;
	else
	{
		if( !target->is_busy() )
			succ_msg = YEL"\n结果$n"YEL"闪避不及，脚下打了个趔趄。\n"NOR;
		else	succ_msg = YEL"\n结果$n"YEL"被半鱼之气打了正着！\n"NOR;
	}
	me->set_temp("pfm_msg",1);	
	me->add("force",-200);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
	me->set_temp("pfm_msg",0);	
	if( random(damage)>10 )
	{
		message_combatd(succ_msg,me,target);
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
	
	msg = HIY"$N"HIY"闭目凝神，心如点转，一招充满太古剑意的阳极半鱼之气使出，看似平淡无奇，实则汇集了天地的元气，铺天盖地的压向$n"HIY"！\n" NOR;
	me->set_temp("pfm_msg",1);	
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,50);
	me->set_temp("pfm_msg",0);	
	i = (me->query_skill("liangyi-sword",1)-100)/50;
	if( i>3 )
		i = 3;
	while(i--)
	{
		if( !me || !living(me) || !target 
		 || !me->is_fighting(target)
		 || me->query("force")<30 )
		 	break;
		message_combatd(HIY"\n$N"HIY"剑意不绝，一招过后，又是一招！\n"NOR,me);
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
	}
	
	msg = HIG "\n$N手中$w"HIG"灵动异常，在剑意已尽之际，又生阴极半鱼，顿时太极之气蓬发，若狂风暴雨般扑向$n"HIG"！\n"NOR;
	me->set_temp("pfm_msg",1);	
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
	me->set_temp("pfm_msg",0);
		 
	me->start_busy(3);		
	return 1;
}

int help(object me)
{
	string str;
	if( !me )      
		return 0;
str = @LONG
        外功名称：双鱼诀
        外功所属：两仪剑法
        外功效果：以「阴字诀」以及「阳字诀」攻击对方
                  自身busy 3 秒
        外功条件：
        	  人物等级20级
        	  两仪剑法200级	
        	  基本剑术200级	
                  内力500点，消耗200点
LONG;
	me->start_more(str);
	return 1;
} 
