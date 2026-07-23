// sanjue 九阴三绝爪

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;

int perform(object me, object target)
{
        int exp, str, dex, skill, i, damage;
	string msg;
        exp = (int)me->query("combat_exp");
        str = (int)me->query("str");
        dex = (int)me->query("dex");
        skill = (int)me->query_skill("jiuyin-shenzhua", 1);
        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「九阴三绝爪」只能在战斗中使用。\n");
        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用「九阴三绝爪」！\n");   
        if(me->query_skill("jiuyin-zhengong",1) < 150 )
                return notify_fail("你的九阴真功还不够娴熟，使不出「九阴三绝爪」绝技。\n");
        if( skill < 150 )
                return notify_fail("你的九阴神爪还不够娴熟，使不出「九阴三绝爪」绝技。\n");
        if ( skill < 200 ) i = 3;
        if ( skill < 300 ) i = 3;
        else i = 3;
        if ( me->query_skill_mapped("claw") != "jiuyin-shenzhua" )
               return notify_fail("你现在无法使用「九阴三绝爪」！\n");
        if( (int)me->query("max_neili") < 800 )
                return notify_fail("你现在内力太弱，使不出「九阴三绝爪」。\n");      
        if( (int)me->query("neili") < 1100 )
                return notify_fail("你现在真气太弱，使不出「九阴三绝爪」。\n");
        me->start_perform(2, "九阴三绝爪");
        message_vision(HIR"\n$N手臂突然伸长，向$n抓去！\n"NOR,me,target);
        message_vision(RED"\n$N所使的似乎是江湖中驰名的阴毒功夫九阴白骨爪，但是招数光明正大，威力强极！\n"NOR,me,target);
	if (!target->is_busy()) target->start_busy(1);
        me->add_temp("apply/strength",str/i);
        me->add_temp("apply/dexerity",dex/i);
        me->add("neili", -600);
        me->add_temp("apply/attack", skill/i);
        me->add_temp("apply/damage", skill/i);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        me->add_temp("apply/damage", -skill/i);
        me->add_temp("apply/attack", -skill/i);
        me->add_temp("apply/strength",-str/i);
        me->add_temp("apply/dexerity",-dex/i);

	msg = HIB "\n$N一声怪啸，绕着$n急转数圈，而后施展出「摧筋破骨」，双爪齐出，直插$n前胸。\n"NOR;
	if (userp(target))
{
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
		msg += HIR"$N已在$n前胸留下了五个整整齐齐的指洞！$n只觉胸口巨痛，鲜血狂喷而出！！！\n"NOR;
		damage = skill * 4 + random(skill);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		if( damage < 300 ) msg += HIY"\n结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
        	else if( damage < 500 ) msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
        	else msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		me->add("neili", - 600);
	} else {
		msg += HIY"$N只觉$n内力浑厚，双爪竟不能惯胸而入。\n" NOR;
	}
	message_vision(msg, me, target);
        me->start_busy(2 + random(i));
if (userp(target)) me->start_busy(4);
}
else{if (random(me->query("combat_exp")) > target->query("combat_exp")/3) {
		msg += HIR"$N已在$n前胸留下了五个整整齐齐的指洞！$n只觉胸口巨痛，鲜血狂喷而出！！！\n"NOR;
		damage = skill * 4 + random(skill);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		if( damage < 300 ) msg += HIY"\n结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
        	else if( damage < 500 ) msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
        	else msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		me->add("neili", - 600);
	} else {
		msg += HIY"$N只觉$n内力浑厚，双爪竟不能惯胸而入。\n" NOR;
	}
	message_vision(msg, me, target);
        me->start_busy(2 + random(i));
if (userp(target)) me->start_busy(4);
}
        return 1;
}
