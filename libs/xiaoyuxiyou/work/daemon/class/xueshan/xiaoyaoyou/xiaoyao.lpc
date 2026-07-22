// 逍遥游 Xiaoyao.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_CLEAN_UP;

void remove_debuff(object who,int p)
{
	if( who )
	{
		who->delete_temp("Debuff_xiaoyao");
		who->add_temp("apply/attack",p);
		tell_object(who,"你逐渐平复了心神。\n");
	}	
}

int perform(object me, object target)
{
	string msg,succ_msg;
	int p,damage,att;
	
	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="大雪山"  
        && me->query("chushi/chushi_xueshan")!="yes")
		return notify_fail("你不能使用这项技能！\n");	
	if( me->query_skill("dodge",1)<180 )
		return notify_fail("你的轻身功夫还不够纯熟！\n");
	if( me->query_skill("xiaoyaoyou",1)<180 )
		return notify_fail("你的逍遥游还不够纯熟！\n");
	if( me->query("force")<800 )
		return notify_fail("你的内力不足。\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「逍遥游」只能对战斗中的对手使用。\n");

	if(target->query_temp("Debuff_xiaoyao"))
		return notify_fail("对方已经被你的身法晃花了眼。\n");
		
	p = me->query_skill("xiaoyaoyou",1);
	p/= 60;
	p+= me->query_cps()/5;
	p+= me->query("betrayer")/10;
	if( p<30 )
		p = 30;
	att = me->query_skill("dodge")/10;
	
	if( target->query("family/family_name") )
	{
		if( target->query("family/family_name") == "大雪山" )
			p = p*3/10+1; 
		att = att/2+1;	
	}
	
	msg = HIY"$N"HIY"忽然运起逍遥游身法，宛如鲲鹏展翅，一啸入云九万里。\n"NOR;
	succ_msg = HIR"转眼不见了$N"HIR"的身行，$n"HIR"只觉目眩神弛，心惊肉跳，顿时一筹莫展！\n"NOR;
	me->add("force",-100);
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
	{
		message_combatd(HIR"不料确被$m"HIR"看破，结果$p并不慌张！\n"NOR,me,target);
		me->start_busy(1);		
	}
	else
	{
		target->set_temp("Debuff_xiaoyao",1);
		target->add_temp("apply/attack",-att);
		call_out("remove_debuff",p,target,att);
	}
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：逍遥游
        外功所属：逍遥游
        外功效果：以身法迷惑对方，使对方在一定时间内命中降低。
                  失败则自身busy 1 秒
                  状态不可叠加
        外功条件：
                  雪山(出师)弟子
        	  人物等级 20 级
                  内力800点，消耗100点
                  基本轻功 180 级
                  逍遥游 180 级
STR;
        me->start_more(str);
        return 1;
}