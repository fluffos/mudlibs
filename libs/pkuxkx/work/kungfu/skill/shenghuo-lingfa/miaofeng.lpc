//miaofeng ZINE

#include <ansi.h>
#include <char.h>
#include <combat.h>
#include "/kungfu/skill/shenghuo-lingfa/shenghuo.h"
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg,color;
    object my_weapon;
    int h;
    mapping attack_val = ([
        "base" : ([ "weapon" : "dagger", ]),//基本功夫类型
        "skill" : ([ "weapon" : "shenghuo-lingfa", ]),//高级技能名称
        ]);

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("妙风使的绝技只能对战斗中的对手使用。\n");

    if (!objectp(my_weapon = me->query_temp("weapon")) || (string)my_weapon->query("skill_type") != "dagger")
/*    if (!objectp(my_weapon = me->query_temp("secondary_weapon")) || (string)my_weapon->query("skill_type") != "dagger") */
        return notify_fail("你右手没有匕首类武器，不能使出妙风使的绝技。\n");

    if( (int)me->query_skill("shenghuo-lingfa",1) < 250 )
        return notify_fail("你的圣火令法等级不够，不能施展妙风使的绝技！\n");

    if( (int)me->query_skill("force", 1) < 200 )
        return notify_fail("你的基本内功等级不够，不能施展妙风使的绝技！\n");

    if( (int)me->query_skill("guangming-shenghuogong", 1) < 200 )
        return notify_fail("你的光明圣火功等级不够，不能施展妙风使的绝技！\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
        me->query_skill_mapped("force") != "guangming-shenghuogong" )
        return notify_fail("妙风使的绝技需要光明圣火功驱动内力！\n");

    if( (int)me->query("neili") < 1500 )
        return notify_fail("你的内力不足，不能施展妙风使的绝技！\n");

    if (time()-me->query_temp("mj_mf_attack")<10)
        return notify_fail("你刚刚才施展过妙风使的绝技。\n");

    if (custom_color(me)==NOR)
        color=BRED;
    else
        color=custom_color(me);

    me->add("neili", -300);
    me->set_temp("mj_mf_attack",time());
    if (me->query("combat_exp")>target->query("combat_exp")&&userp(me))
    {
        me->add_temp("apply/attack",me->query_skill("shenghuo-lingfa"));
        me->add_temp("apply/damage",me->query_skill("shenghuo-lingfa"));
    }
    msg = color+"$N"+color+"忽然低头，一个头锤向$n"+color+ "撞来，如此打法原是武学中大忌，竟以自己最要紧的部位送向敌人。\n$n"+color+ "端立不动，知$N"+color+ "这一招似拙实巧，必定伏下厉害异常的后招。"NOR;
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, my_weapon, TYPE_SPECIAL, msg);

    msg = color+ "蓦地里$N"+color+ "跃身半空，向$n"+color+ "头顶坐了下来。这一招更是怪异，竟以臀部攻人，天下武学之道虽繁，从未有这一路既无用、又笨拙的招数。" NOR;
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, my_weapon, TYPE_SPECIAL, msg);
    if (me->query("combat_exp")>target->query("combat_exp")&&userp(me))
    {
        me->add_temp("apply/attack",-me->query_skill("shenghuo-lingfa"));
        me->add_temp("apply/damage",-me->query_skill("shenghuo-lingfa"));
    }

    return 1;
}
