// Pingfeng.c 石破天惊
// Cracked by 凌惊雪 1-17-2003
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
 
int perform(object me, object target)
{
	object weapon;
	string msg;
	int skill,extra,damage;
	
	if( me->query_skill("xuehejue",2)>=1 )
		return notify_fail("你既然已经学了血河诀，就不能三心二意。\n");
		    
	skill=(int)me->query_skill("pingfeng",1);
	if( !target ) 
		target = offensive_target(me);
	if( !target
 	 || !target->is_character()
 	 || !me->is_fighting(target) )
		return notify_fail("「石破天惊」只能在战斗中使用。\n");
	if( (int)me->query("force") < 500 )
        	return notify_fail("你的真气不够！\n");
	if( time()-(int)me->query_temp("pfm_pingfeng") < 5 )
        	return notify_fail("绝招用多就不灵了！\n");                
	if( (int)me->query_skill("pingfeng",1) < 100 )
        	return notify_fail("你的屏风四扇门火候不够，无法使用「石破天惊」！\n");
	if( (int)me->query_skill("force",1) < 100 )
        	return notify_fail("你的内功修为不够，无法使用「石破天惊」！\n");
	msg = HIC "$N"HIC"心如止水，无意之中使出了「"HIR"石破天惊"HIC"」！\n" NOR;
	message_vision(msg, me);
	me->set_temp("pfm_pingfeng",time());
	me->add("force",-150);
	
	if(me->query_skill_mapped("force")=="pingfeng")
        {
        	message_combatd(HIR"$N"+HIR"只觉一尊天神从天而降，发须直立，吓得两腿发抖。\n"NOR,target);
        	if ((int)target->query("sen")>skill)
                	target->receive_damage("sen", skill,me);
        }

	extra = (int)me->query_skill("unarmed")/15;
	if( extra>50 )
		extra =50;
	me->add_temp("apply/attack",extra);
	
	damage = me->query_skill("pingfeng",1);
	if( damage>1500 )
		damage = 1500;
	
	msg = HIR"          石字决！\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_QUICK,msg,0,0,damage/3);

	msg = HIY"          破字决！\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_QUICK,msg,0,0,damage/2);
	
	msg = HIC"          天字决！\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,damage);

	msg = HIW"          惊字决！\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,damage);
          
	me->add_temp("apply/attack",-extra);
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：石破天惊
        外功所属：屏风四扇门
        外功效果：对敌连续攻击四次，冷却5秒
                  固定伤害递增
        外功条件：
                  内力500点，消耗150点
                  内功心法 100 级
                  屏风四扇门 100 级
STR;
        me->start_more(str);
        return 1;
}