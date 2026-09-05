// tianlei.c 铁掌--凝血神抓

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage, force;
        string msg;
        object weapon;

	 // dewolf 大弟子判定
    if( me->query("family/family_name")!="天地会" || !me->query("family/topone") )
        return notify_fail("只有本派大弟子才有权使用凝血神爪对敌！\n");
		
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("凝血神抓只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("yunlong-zhua", 1) < 150 )
		return notify_fail("你的凝血神抓还未练成，不能使用！\n");

        if( (int)me->query("neili", 1) < 600 )
		return notify_fail("你现在内力不足，不能使用凝血神抓！\n");

	if( (int)me->query_skill("yunlong-zhua", 1) < 120 )
		return notify_fail("你的云龙抓不够娴熟，不能使用凝血神抓。\n");

    msg = RED "\n$N把全身的劲力注入双掌,高高跃起，**凝血神抓**，一抓抓来，势不可挡！\n"NOR;

	if( weapon = target->query_temp("weapon") ){
        if( random(me->query_str()) > (int)target->query_str()/2 ) {
    msg += HIM"\n$p只觉得浑身一热，手掌虎口巨痛，手中"
                + target->query_temp("weapon")->query("name") + "脱手而出。\n" NOR;
		message_vision(msg, me, target);
                 target->query_temp("weapon")->unequip();
                 destruct(target->query_temp("weapon"));
		force = 200;
	}
	else {
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
		message_vision(msg, me, target);
		force = 100;
	}
	me->start_busy(2);
        }
        else
        {
        if( random(me->query_str()) > (int)target->query_str()/2 )
	{
		me->start_busy(3);
		target->start_busy(random(4));

		damage = (int)me->query_skill("yunlong-zhua", 1);

		damage = 3 * damage + 2 * random(damage);

		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/2, me);

		if( damage < 300 ) msg += HIY"\n结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
        	else if( damage < 500 ) msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
        	else msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
        	force = 500;

	} else
	{
		me->start_busy(1);
    		msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
    		force = 100;
	}
	message_vision(msg, me, target);
        if(wizardp(me)) tell_object(me, "ningxue damage: " + damage +"。\n\n");
        }

        me->add("neili", - force);
	return 1;
}
