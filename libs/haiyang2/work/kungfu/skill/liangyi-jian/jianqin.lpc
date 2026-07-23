// tianlei.c 

#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
        string msg;
        object weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("琴剑双绝只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
		return notify_fail("手中无剑,你怎么使得出琴剑双绝！\n");

        if( (int)me->query_skill("art", 1) < 200 )
		return notify_fail("你的琴棋书画还未练成，不能使用！\n");

        if( (int)me->query_skill("liangyi-jian", 1) < 200 )
		return notify_fail("你的两仪剑法还未练成，不能使用！\n");

        if ((int)me->query_skill("xuantian-wuji", 1) < 100)
                return notify_fail("你的玄天无极功火侯太浅。\n"); 

        if( (int)me->query("neili", 1) < 600 )
		return notify_fail("你现在内力不足，不能使用琴剑双绝！\n");	

    if( (int)me->query_skill("xuantian-wuji", 1) > 200 )
    {
    msg = HIC"$n看到剑光偏左，疾侧身右转，但只这一刹，剑光刹时袭向右首！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"$n看到剑光偏右，疾侧身左转，但只这一刹，剑光刹时袭向左首！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"$n看到剑光偏上，疾侧身下转，但只这一刹，剑光刹时袭向下身！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"$n看到剑光偏下，疾侧身上转，但只这一刹，剑光刹时袭向上身！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    }

    msg = HIY "\n$N忽然仰天大喝一声“琴 剑 双 绝”，手上的剑如风车般连环击出，一阵热浪随剑势狂飙而出，势不可挡！\n"NOR;

	if( weapon = target->query_temp("weapon") ){
    if (random(me->query_skill("force")) > target->query_skill("force")/2|| 
       random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
{  
    msg += HIM"\n$p只觉得浑身一热，手掌虎口巨痛，手中"
                + target->query_temp("weapon")->query("name") + "脱手而出。\n" NOR;
		message_vision(msg, me, target);
		(target->query_temp("weapon"))->move(environment(target));
		target->start_busy(2);
	} else {
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
		message_vision(msg, me, target);
	}
	me->start_busy(2);
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/2 ||
          random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("art", 1);
		
		damage = damage*5 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIY"\n结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
        	else if( damage < 500 ) msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
        	else msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		
	} else 
	{
		me->start_busy(2);
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
	}
	message_vision(msg, me, target);

        }
        me->add("neili", -400);
	return 1;
}
