// throw.c 灵蛇杖法喷毒
// By Yzuo 97.04

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    object weapon;
    string msg;
	int pflv;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() ) 
        return notify_fail("怪蛇攻击只能对同地方的对手使用。\n");

    if( (int)me->query_skill("hamagong", 1) < 40 )
        return notify_fail("你的蛤蟆功不够娴熟，不能驱动怪蛇攻击。\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        (string)me->query("family/family_name") != "白驼山" && (string)me->query("chushi/last_menpai")!="白驼山" )
        return notify_fail("你的师傅会驱动怪蛇么？\n");

    if( (int)me->query_skill("lingshe-zhangfa", 1) < 40 )
        return notify_fail("你的灵蛇杖法不够娴熟，不能驱动怪蛇攻击。\n");
	
    if( (int)me->query_skill("poison", 1) < 50 )
        return notify_fail("你的施毒技艺不够娴熟，不能驱动怪蛇攻击。\n");	

    if( (int)me->query("neili", 1) < 400 )
        return notify_fail("你的内力不够，不能驱动怪蛇攻击。\n");

    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你需要装备staff类武器才能使用怪蛇攻击的绝招。\n");

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "白驼山") 
		pflv=0;

	if( (pflv<=0) && (string)weapon->query("id") != "she zhang" )
        return notify_fail("你手中没有蛇杖，杖上没有怪蛇可供驱动。\n");

    me->add("neili", -100);

    msg = HIB+"$N口中呼啸一声，手臂上气血虬结，内力汹涌催动整根蛇杖，"+HIR+"杖"+HIW+"头"+HIR+"小"+HIW+"蛇"+HIB+"全身变作"+HIG+"碧绿色"+HIB+"，瞬间鼓涨成球！\n";
	msg += "$N大喝一声，"+HIG+"怪蛇"+HIB+"如簧般弹起电射而出，大张"+HIR+"血口"+HIB+"，向着"+target->name()+"的脖颈一口直咬下去！"+NOR+"\n";

    me->start_busy(1);
//命中率级别C-&C-=E级   注：重新调整为C&A=D+级，降低攻击的直接伤害 by lordstar@20170918
    if( F_KUNGFU->hit_rate( (int)me->query_skill("staff", "lingshe-zhangfa"), target->query_skill("dodge"), 8, me, target) )
    {   	
        if ( F_KUNGFU->hit_rate( me->query("max_neili"), target->query("max_neili"), 2, me, target) )
        {
            msg += YEL+target->name()+"已不及闪躲，危急中只能把脖子一歪，"+HIG+"怪蛇"+NOR+YEL+"一口咬在了"+target->name()+"的肩膀上！\n" NOR;
            msg += HIY+target->name()+HIY"被咬处不觉疼痛，却感到四肢逐渐麻木，胸中烦闷欲呕！\n" NOR;
            F_KUNGFU->hit_wound("qi", (int)me->query_skill("lingshe-zhangfa",1)/5, 1 + random(me->query_skill("lingshe-zhangfa",1))/5, me, target);
            target->receive_wound("jing", 10, me);
            //target->set_temp("death_cond_origin/snake_poison", me);
			// 调整为白驼怪蛇毒 by lordstar@20170918
			F_POISON->poison_attack(me,target,"btgs_poison", random(me->query_skill("poison",1)/5) + 1 +  target->query_condition("btgs_poison"));
			target->set_temp("btgs_poison/pflv", pflv);
            if ( !target->is_busy() )
              target->start_busy(1 + random(2));
            message_vision(msg, me);
            COMBAT_D->report_status(target);
        }
        else
        {
            msg += CYN+target->name()+CYN"急运内力一掌劈出，掌力张开成一道气墙，击得"HIG"怪蛇"CYN"反卷向$N飞了回去！\n" NOR;
            msg += MAG "$N鼻中闻到一阵甜香，似是"HIG"怪蛇"NOR+MAG"的毒涎飞溅到了自己脸上。\n" NOR;
//            F_KUNGFU->hit_wound("qi", (int)me->query_skill("lingshe-zhangfa",1), 15 + random(me->query_skill("lingshe-zhangfa",1)), target, me);
            me->receive_wound("jing", 10, "中蛇毒");
            //me->set_temp("death_cond_origin/snake_poison", target);
			F_POISON->poison_attack(target,me,"btgs_poison", random(5) + 1 + me->query_condition("btgs_poison"));
			me->set_temp("btgs_poison/pflv", 0);
            me->start_busy(1 + random(2));
            message_vision(msg, me);
            COMBAT_D->report_status(me);
        }
    } else {
        msg += WHT+target->name()+WHT"早已料到这杖头毒蛇有古怪，早已纵身后跃，从容飘至三丈余外，便是连衣衫上也不曾落得半点毒液。\n" NOR;
        me->start_busy(3);
        message_vision(msg, me);
    }
    if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
    return 1;
}
