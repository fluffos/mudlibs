// 开天辟地
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage,p;
	string msg,succ_msg;

	if( me->query_level()<8 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query("force")<500)
        	return notify_fail("你的内力不足！\n");
	if( me->query("kee")<100 )
        	return notify_fail("你的气血不足，没法子施用外功！\n");
	if((int)me->query_skill("sanban-axe", 1) <80)
        	return notify_fail("你的宣花斧级别还不够！\n");
	if( me->query("family/family_name")!="将军府" 
 	&& me->query("chushi/chushi_jjf")!="yes")
        	return notify_fail("你不能使用这项技能！\n"); 
	weapon=me->query_temp("weapon");
	if( !weapon
	 || ( weapon->query("skill_type")!="axe"
	   && weapon->query("use_apply_skill")!="axe" ) )		
        	return notify_fail("你的斧子呢？\n");
        	
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me
 	|| !me->is_fighting(target) )
        	return notify_fail("你要对谁施展这一招"+HIM"「开天」"+NOR"？\n");

	me->add("force", -200);
	me->receive_damage("kee", 100);

	msg = HIC"$N"HIC"突然暴喝一声，将手中$w"HIC"斜向上举起，然后在半空中划出一道圆弧，随即径直斜下斩向$n"HIC"$l！这一瞬间，$n"HIC"只觉得呼吸都停止了！\n"NOR;
	succ_msg =  HIR"结果一道寒光从$n"HIR"当头劈过,带出一地鲜血！\n" NOR;       
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,({"头部","胸部","后心",})[random(3)],50);
	if( damage>0 )
	{
		target->receive_wound("sen",damage,me,TYPE_PERFORM);
		target->receive_damage("sen",damage,me,TYPE_PERFORM);
		COMBAT_D->report_sen_status(target);
	}
	me->start_busy(3);
	return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：开天斩
        外功所属：宣花三斧
        外功效果：对敌进行带固定伤害的要害攻击，如击中则使对方精神也受打击
        	  使用后自身busy 3 秒
        外功条件：
                  将军府(出师)弟子
                  人物等级8级 
                  内力500点，消耗200点
                  气血100点，消耗100点
                  宣花三斧80级
LONG;
me->start_more(str);
return 1;
}

