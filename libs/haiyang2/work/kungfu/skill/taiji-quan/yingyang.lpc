// yingyang 显阴阳
// updated force->neili, force_factor->jiali (by xbd)

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,damage;
	int orforce;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("这个绝技只能空手使用。\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("taiji-quan", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

       if( !wizardp(me) &&(int)me->query_skill("taiji-jian", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("taiji-shengong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

        if( !wizardp(me) && me->query_temp("weapon") )
                return notify_fail("你必须空手才能使用本门绝学!\n");

//    if (!objectp(weapon = me->query_temp("weapon"))
//        || (string)weapon->query("skill_type") != "sword")
//        return notify_fail("开什么玩笑，没装备剑就想使「漫天飞雪」？\n");


        extra = me->query_skill("taiji-shengong",1);
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");

	me->add("jiali",extra/3);
	orforce = (int) me->query("force");
//	me->add("neili",extra/3*100);

	weapon = me->query_temp("weapon");
	me->add("str", extra/6);
	me->add_temp("apply/attack",extra/2);
	me->add_temp("apply/damage",extra*2);

        msg = HBWHT "$N贯通武当武学，使出了武当的绝学之精髓！\n" NOR;
        message_vision(msg, me, target);               

	msg = MAG  "$N双手抱了个太极式的圆圈，纯以意行太极，已达形神合一，心动气动的境界，！\n"NOR;
	message_vision(msg,me,target);
	msg = WHT  "「乱环诀」！阴" NOR;

if (random(3)==0) target->start_busy(3);

	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "「乱环诀」！阳" NOR;
        target->receive_wound("qi", random(extra));
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "「阴阳诀」！阴" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "「阴阳诀」！阳" NOR;
        target->receive_wound("qi", random(extra));
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "「动静诀」！阴" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "「动静诀」！阳" NOR;
        target->receive_wound("qi", random(extra));
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "「两仪诀」！阴" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "「两仪诀」！阳" NOR;
        target->receive_wound("qi", random(extra));
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "「刚柔诀」！阴" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "「刚柔诀」！阳" NOR;
        target->receive_wound("qi", random(extra));
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
                msg = WHT"              阴阳双环           !!\n"NOR;
		msg += MAG"「沾黏诀」「挤字诀」「引字诀」「按字诀」!!\n"NOR;
		damage = extra * 6 + random(extra);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		if( damage < 300 ) msg += HIY"\n结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
        	else if( damage < 500 ) msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
        	else msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
	message_vision(msg, me, target);
}
	
        me->start_busy(4);
	me->set("jiali",0);
         me->add("str", -extra/6);
        me->add_temp("apply/attack",-extra/2);
        me->add_temp("apply/damage",-extra*2);
	me->add("neili", -me->query("max_neili")/7);
	return 1;
}
