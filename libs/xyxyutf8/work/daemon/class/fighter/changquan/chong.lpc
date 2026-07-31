// 冲字诀 Chong.c
// Cracked by Roath
// Last updated By 凌惊雪 1.12.2003
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg,succ_msg;
	int p;
	
	if( me->query_level()<8 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query_skill("changquan",1)<80
	 || me->query_skill("unarmed",1)<80	
	 || me->query_skill_mapped("unarmed")!= "changquan" )
		return notify_fail("你的拳脚功夫还不到家。\n");
	if(me->query("family/family_name") != "将军府")
        	return notify_fail(HIR"「冲字诀」"+NOR"是将军府不传之密！\n");
        if( time()<me->query_temp("jjf_chong")+8 )
        	return notify_fail("绝招用多就不灵了。\n");
	if( (int)me->query("force") < 500 )
        	return notify_fail("你现在的内力不足！\n");
				 
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me
 	|| !me->is_fighting(target) )  
        	return notify_fail("「冲字诀」只能在战斗中使用。\n");
	
	p = me->query_skill("unarmed");
	if( p>500 )
		p = 500;
	me->add("force",-300);	
	msg = HIY "$N"HIY"突然向前迈上三大步，气沉丹田，一声闷喝，右拳一记「冲天炮」自腰间猛然挥出，势若奔雷、快若闪电却又简简单单、全无花巧，直奔$n"HIY"$l而去！\n"NOR;
	succ_msg = HIR "$n"HIR"躲闪不及，“嘭”一声闷响，$l已然塌了下去，顿时脸色变得煞白，一口鲜血狂喷而出。\n"NOR;
	me->add_temp("apply/attack",p/5);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,0,p);
	me->add_temp("apply/attack",-p/5);
        me->set_temp("jjf_chong",time());
        return 1;
}

int help(object me)
{
string str;
if ( !me )      return 0;

str = @LONG
        外功名称：冲字诀
        外功所属：长拳
        外功效果：给予对手带最高500点固定伤害的物理攻击
                  冷却时间8秒
        外功条件：
                  将军府弟子
                  内力500点，消耗300点
                  扑击格斗80级，并激发长拳
                  长拳80级
LONG;
me->start_more(str);
return 1;
}

