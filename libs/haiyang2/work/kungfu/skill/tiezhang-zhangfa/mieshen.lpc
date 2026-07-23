// mieshen

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i,a,damage;
	object weapon;
	if( !target ) target = offensive_target(me);

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("只能空手使用。\n");		
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("shuishangpiao", 1) < 500 )
		return notify_fail("你的本门轻功不够!不能贯通使用！\n");

       if( !wizardp(me) &&(int)me->query_skill("tiezhang-zhangfa", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("guiyuan-tunafa", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "guiyuan-tunafa")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

        msg = HBWHT "$N贯通铁掌武学，使出了铁掌的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);   

	extra = me->query_skill("tiezhang-zhangfa",1) / 20;
	extra += me->query_skill("guiyuan-tunafa",1) /20;
 i = extra/4;
    if( (int)me->query("neili", 1) <  (80 * i) )
		return notify_fail("你现在内力不足，不能使用！\n");	
        me->add_temp("apply/strength", extra/2);
        me->add_temp("apply/attack", extra*2);    
        me->add_temp("apply/damage", extra*2);
	if (random(3)==0) target->start_busy(3);
	msg = HIR  "$N运起［归元吐纳法］，同时使出［铁掌降龙］一阵一阵的掌力，如潮水般的击向$n！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIW "第一层掌力，．．．．\n" NOR;
        message_vision(msg, me, target);
a=extra/3;
if (a>8) a=8;
        for(i=0;i<a;i++)
	{
	msg = HIC "$N身形突转，一掌又打了过来！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
i = extra/4;
        me->add_temp("apply/strength", -extra/2);
        me->add_temp("apply/attack", -extra*2);
        me->add_temp("apply/damage", -extra*2);
me->start_busy(4);
        me->add_temp("apply/attack", extra*2);    
        me->add_temp("apply/damage", extra*2);
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
        me->add_temp("apply/damage", -extra*2);
target->apply_condition("tiezhang_yang",50);
target->apply_condition("tiezhang_yin",50);

    msg = HIY "\n$N忽然仰天大喝一声“天 雷 气”，双掌如风车般连环击出，一阵热浪随掌势狂飙而出，势不可挡！\n"NOR;

	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("str")) > (int)target->query("str")/2 ) {  
    msg += HIM"\n$p只觉得浑身一热，手掌虎口巨痛，手中"
                + target->query_temp("weapon")->query("name") + "脱手而出。\n" NOR;
		message_vision(msg, me, target);
		(target->query_temp("weapon"))->move(environment(target));
	} else {
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
		message_vision(msg, me, target);
	}
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/3 
        ||          random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
	{
		target->start_busy(random(3)+1);
		
		damage = (int)me->query_skill("guiyuan-tunafa", 1);
		
                damage = damage*6 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIY"\n结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
        	else if( damage < 500 ) msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
        	else msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		
	} else 
	{
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
	}
	message_vision(msg, me, target);

        }

	return 1;

	return 1;
}
