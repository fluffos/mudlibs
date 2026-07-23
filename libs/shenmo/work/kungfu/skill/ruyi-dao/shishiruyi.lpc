// mie.c  回风拂柳剑法「事事如意」

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
		return notify_fail("［事事如意］只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("开什么玩笑，没装备刀就想使「事事如意」？\n");
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「事事如意」只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("beiming-shengong", 1) < 60 )
                return notify_fail("你的「北冥神功」不够娴熟。\n");

        if ((int)me->query_skill("ruyi-dao", 1) < 200 )
                return notify_fail("你的如意刀不够娴熟，还使不出「事事如意」。\n");
        if ((int)me->query("max_neili")<800)
                return notify_fail("你的内力修为不足，无法运足「事事如意」的内力。\n");
        if ((int)me->query("neili")<200)
                      return notify_fail("你现在内力不够，没能将「事事如意」使完！\n");
        msg = HIC "$N手中长刀刀芒跃动，刀光暴长，一刀砍出，刀尖渐渐逼近$n，\n"NOR;
        msg += HIM"$n看到漫天刀光，抽身后跃，只这一刹，漫天刀影化为一刀直劈$n前胸，\n"NOR;
        msg += HIR"**************事事如意***************"NOR;
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
        if (random(me->query_skill("force")) > target->query_skill("force")/3 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("ruyi-dao", 1);
		
		damage = damage*3 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIC"\n结果$n脸色被一刀砍中，昏昏沉沉接连退了好几步！\n"NOR;
        	else if( damage < 400 ) msg += HIC"\n结果一刀砍中，$n「哇」地一声吐出一口鲜血！\n"NOR;
        	else if( damage < 500 ) msg += HIR"\n结果「轰」地一声，一刀正砍中正胸,$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
        	else msg += HIR"\n结果只听见几声喀喀轻响，一刀砍中正胸,$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		
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