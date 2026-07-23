//xiaoyao 逍遥刀

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
        int skill;
	int extra;
        string msg;
        int damage;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
                return notify_fail("必须用刀才能施展。\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("ruyi-dao", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("liuyang-zhang", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("beiming-shengong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通逍遥派武学，使出了逍遥派的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);              

        
        skill = me->query_skill("ruyi-dao");
	extra = me->query_skill("ruyi-dao",1) / 20;
	extra += me->query_skill("ruyi-dao",1) /20;
        me->set_temp("ruyi");
	if (random(3)==0) target->start_busy(3);
	me->add_temp("apply/attack", extra*2);	
	me->add_temp("apply/damage", extra*3);
        msg = HIY "$N一声长笑，只觉世事如意，豪气满胸，哪管什么是非荣辱，反手一刀砍出！\n"NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB"$N刀风过处，意犹未尽，反手又是一刀！\n"NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("ruyi-dao",1)));
        msg = HIR"$N身随刀转，顺手又是一刀！\n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("ruyi-dao",1)));
        msg = HIG"$N身随刀转，顺手再是一刀！\n"NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("ruyi-dao",1)));
        msg = HIC"$N身随刀转，顺手最后一刀！\n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("ruyi-dao",1)));
        msg = HIW"$N身形再转，如意一刀又回转回来！\n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("ruyi-dao",1)));
	msg = BLU "$N化水为冰，凝于掌中，双指一弹，手上几道青光急速射向$n。\n";
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("ruyi-dao",1)));
	target->apply_condition("ss_poison", random(me->query_skill("liuyang-zhang",1)/50) + 2 +
	target->query_condition("ss_poison"));

       me->start_busy(4);
       me->delete_temp("ruyi");
	me->add_temp("apply/attack", -extra*2);
	me->add_temp("apply/damage", -extra*3);
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
        }
        else
        {
 if (random(me->query("combat_exp")) >target->query("combat_exp")/3)
	{
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("ruyi-dao", 1);
		
		damage = damage*6 + random(damage)+800;
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIC"\n结果$n脸色被一刀砍中，昏昏沉沉接连退了好几步！\n"NOR;
        	else if( damage < 400 ) msg += HIC"\n结果一刀砍中，$n「哇」地一声吐出一口鲜血！\n"NOR;
        	else if( damage < 500 ) msg += HIR"\n结果「轰」地一声，一刀正砍中正胸,$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
        	else msg += HIR"\n结果只听见几声喀喀轻响，一刀砍中正胸,$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		
	} else 
	{
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
	}
	message_vision(msg, me, target);

        }

        return 1;
}
