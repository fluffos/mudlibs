// tianlei.c 铁掌--凝血神抓

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
        string msg;
        object weapon;
int extra;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("凝血神抓只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用凝血神抓！\n");

        if( (int)me->query_skill("yunlong-zhua", 1) < 199 )
		return notify_fail("你的凝血神抓还未练成，不能使用！\n");

        if (me->query_skill("yunlong-shengong", 1)<70)
                return notify_fail("你的本门内功火候未到，！\n");

        if( (int)me->query("neili", 1) < 600 )
		return notify_fail("你现在内力不足，不能使用凝血神抓！\n");	

	if( (int)me->query_skill("yunlong-zhua", 1) < 119 )
		return notify_fail("你的云龙抓不够娴熟，不能使用凝血神抓。\n");

    msg = RED "\n$N把全身的劲力注入双掌,高高跃起，**凝血神抓**，一抓抓来，势不可挡！\n"NOR;
		message_vision(msg, me, target);

    if( (int)me->query_skill("yunlong-shengong", 1) > 200 )
    {
	extra = me->query_skill("yunlong-zhua",1) / 15;
	extra += me->query_skill("yunlong-zhua",1) /15;
	me->add_temp("apply/attack", 80);	
	me->add_temp("apply/damage", extra);
    msg = HIC"左一爪！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"右一爪！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"上一爪！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"下一爪!"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->apply_condition("zhua_poison",10);
	me->add_temp("apply/attack", -80);	
	me->add_temp("apply/damage", -extra);

}
	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("str")) > (int)target->query("str")*3/4 ) {  
    msg += HIM"\n$p只觉得浑身一热，手掌虎口巨痛，手中"
                + target->query_temp("weapon")->query("name") + "脱手而出。\n" NOR;
		message_vision(msg, me, target);
		(
		target->query_temp("weapon"))->move(environment(target));
		target->start_busy(2);
	} else {
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
		message_vision(msg, me, target);
	}
	me->start_busy(1);
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/2 
        || random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(4));
		
		damage = (int)me->query_skill("yunlong-shengong", 1);
		
		damage = damage*4 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIY"\n结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
        	else if( damage < 500 ) msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
        	else msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		
	} else 
	{
		me->start_busy(1);
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
	}
	message_vision(msg, me, target);

        }
        me->add("neili", -300);
	return 1;
}
