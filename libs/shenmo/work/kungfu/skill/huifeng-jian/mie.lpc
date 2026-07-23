// mie.c  回风拂柳剑法「灭剑」

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
		return notify_fail("［灭剑］只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("开什么玩笑，没装备剑就想使「灭剑」？\n");
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「灭剑」只能对战斗中的对手使用。\n");
        if ((int)me->query_skill("huifeng-jian", 1) < 200 )
                return notify_fail("你的回风拂柳剑法不够娴熟，还使不出「灭剑」。\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 100 )
                return notify_fail("你的临济十二庄火候不够，「灭剑」不成招式。\n");
        if ((int)me->query("max_neili")<800)
                return notify_fail("你的内力修为不足，无法运足「灭剑」的内力。\n");
        if ((int)me->query("neili")<600)
                      return notify_fail("你现在内力不够，没能将「灭剑」使完！\n");
	extra = me->query_skill("huifeng-jian",1) / 10;
	extra += me->query_skill("huifeng-jian",1) /10;

    if( (int)me->query_skill("linji-zhuang", 1) > 200 )
    {
        me->add_temp("apply/attack", extra*4);
        me->add_temp("apply/damage", extra*2);
        msg = HIC "只见$N左手一抖，"+ weapon->name()+ HIY"划向$n的右肩！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY "只见$N右手一抖，"+ weapon->name()+ HIY"划向$n的左肩！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIW "$N凌空一劈，"+ weapon->name()+ GRN"削向$n的右肩！" NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN "$N长啸一声，聚功力于左手，使出剑法的最高境界--灭剑，朝$n的胸前劈去！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra*4);
        me->add_temp("apply/damage", -extra*2);

}
               
        msg = YEL "$N手中长剑剑芒跃动，剑光暴长，幻出死亡的色彩，剑尖渐渐逼近$n，\n"NOR;
        msg += YEL"$n看到漫天剑光，抽身后跃，只这一刹，漫天剑影化为一剑直刺$n前胸，"NOR;

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
          message_vision(HIW "但$N飘身而起，使出峨嵋绝技「灭剑」心法，顿时剑意空灵飘逸，似万千柳絮飞舞，又如和风阵阵
拂过。$n惊骇之下，顿时出招散乱，无从招架！\n" NOR, 
                         me, target);
       target->start_busy(2);
	}
	me->start_busy(3);
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/2 
        || random(me->query("combat_exp"))+5000 > target->query("combat_exp")/2 )
	{
		me->start_busy(2);
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("huifeng-jian", 1);
		
		damage = damage*4 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIY"\n结果$n脸色被一剑击中，昏昏沉沉接连退了好几步！\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n结果一剑击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
        	else if( damage < 500 ) msg += RED"\n结果「轰」地一声，一剑穿心,$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
        	else msg += HIR"\n结果只听见几声喀喀轻响，一剑穿心,$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		
	} else 
	{
		me->start_busy(3);
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
	message_vision(msg, me, target);
            message_vision(HIW "但$N飘身而起，使出峨嵋绝技「灭剑」心法，顿时剑意空灵飘逸而，似万千柳絮飞舞，又如和风阵阵
拂过。$n虽已加倍提防，但仍感攻势频频收挫。\n" NOR, 
me, target);
        target->add("jing",-extra);
        target->add("eff_jing",-extra/2);
        target->add("qi",-extra);
        target->add("eff_qi",-extra/2);
	}
	message_vision(msg, me, target);

        }
        me->add("neili", -480);
	return 1;
}