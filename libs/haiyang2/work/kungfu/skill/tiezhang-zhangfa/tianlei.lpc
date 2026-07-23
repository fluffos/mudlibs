// tianlei.c 铁掌--天雷气

#include <ansi.h>


#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
        int extra;
        string msg;
        object weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("天雷气只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用天雷气！\n");

        if( (int)me->query_skill("guiyuan-tunafa", 1) < 119 )
		return notify_fail("你的天雷气还未练成，不能使用！\n");

        if( (int)me->query("neili", 1) < 600 )
		return notify_fail("你现在内力不足，不能使用天雷气！\n");	

	if( (int)me->query_skill("tiezhang-zhangfa", 1) < 119 )
		return notify_fail("你的铁掌掌法不够娴熟，不能使用天雷气。\n");

   if (me->query_skill_mapped("unarmed") != "tiezhang-zhangfa"
     ||me->query_skill_prepared("strike") != "tiezhang-zhangfa")
                return notify_fail("你没有把铁掌做为基本招架和备为掌法。\n");

        extra = me->query_skill("tiezhang-zhangfa",1) / 20;
	extra += me->query_skill("guiyuan-tunafa",1) /20;
    if( (int)me->query_skill("guiyuan-tunafa", 1) > 200 )
    {
        me->add_temp("apply/attack", extra*2);    
        me->add_temp("apply/damage", extra*3);
	    msg = HIC"$N左一掌！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"$N右一掌！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"$N上一掌！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"$N下一掌！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"$N最后一掌！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili",-150);
        me->add_temp("apply/attack", -extra*2);    
        me->add_temp("apply/damage", -extra*3);

    }


    msg = HIY "\n$N忽然仰天大喝一声“天 雷 气”，双掌如风车般连环击出，一阵热浪随掌势狂飙而出，势不可挡！\n"NOR;

	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("str")) > (int)target->query("str")/2 ) {  
    msg += HIM"\n$p只觉得浑身一热，手掌虎口巨痛，手中"
                + target->query_temp("weapon")->query("name") + "脱手而出。\n" NOR;
		message_vision(msg, me, target);
		(target->query_temp("weapon"))->move(environment(target));
		target->start_busy(3);
	} else {
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
		message_vision(msg, me, target);
	}
	me->start_busy(1);
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/3 
        ||          random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("guiyuan-tunafa", 1);
		
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
