// 窒气诀 Chong.c
// Cracked by Roath
// Last updated By 凌惊雪 1.12.2003
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg,succ_msg;
	int damage,p;
	
	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query_skill("changquan",1)<100
	 || me->query_skill("unarmed",1)<100	
	 || me->query_skill_mapped("unarmed")!= "changquan" )
		return notify_fail("你的拳脚功夫还不到家。\n");
	if(me->query("family/family_name") != "将军府")
        	return notify_fail(HIR"「窒气诀」"+NOR"是将军府不传之密！\n");
	if( (int)me->query("force") < 800 )
        	return notify_fail("你现在的内力不足！\n");
				 
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me
 	|| !me->is_fighting(target) )  
        	return notify_fail("「窒气诀」只能在战斗中使用。\n");
	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
		
	p = me->query_skill("unarmed");
	p/= 30;
	if( p>5 )
		p = 5;
	p+= 1;	
	me->add("force",-100);	
	msg = HIY "$N"HIY"收拳发力，招化长拳之秘奥义[窒气诀]向$n"HIY"攻去！\n"NOR;
	succ_msg = HIB "$n"HIB"被一阵拳风扫中，身形不由慢了下来。\n" NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg);
	me->set_temp("pfm_msg",0);
	if( damage>0 )
		target->start_busy(p);
	else
	{
		message_combatd(HIG "可是$p连跳了几步，闪开了这阵拳风！\n" NOR,me,target);
		me->start_busy(3);	
	}	
        me->start_busy(2);
        return 1;
}

int help(object me)
{
string str;
if ( !me )      return 0;

str = @LONG
        外功名称：窒气诀
        外功所属：长拳
        外功效果：使对手最高busy 6 秒
                  使完后自身busy 2 秒
                  失败自身busy 3 秒
        外功条件：
                  将军府弟子
                  内力800点，消耗100点
                  扑击格斗100级，并激发长拳
                  长拳100级
LONG;
me->start_more(str);
return 1;
}

