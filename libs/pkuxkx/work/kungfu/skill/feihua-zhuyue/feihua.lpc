//feihua.c -飞花逐月

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;
inherit YIZHAOYUN;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg;
    int rate_level,agile_wt;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
            return notify_fail("「飞花逐月」只能对战斗中的对手使用。\n");

//        if( !me->query("feihua"))
//                return notify_fail("你的外功中没有这种功能。\n");

    if (base_name(environment(me))[0..10] == "/d/changbai")
            return notify_fail("什么？\n");

    if( objectp(me->query_temp("weapon")) )
            return notify_fail("你必须空手才能施展「飞花逐月」！\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) &&  
       me->query_skill_mapped("force")!="beiming-shengong" )
        return notify_fail("必须激发北冥神功才能使出「飞花逐月」！\n");

    if ( me->query_skill("force", "beiming-shengong") < 500 )
            return notify_fail("你的北冥神功等级不够，无法施展「飞花逐月」。");

    if (me->query_skill("finger", "feihua-zhuyue") < 500 )
            return notify_fail("你的飞花逐月等级不够，施展不出「飞花逐月]。\n");

    if (me->query("neili")<2500||me->query("max_neili")<5000)
            return notify_fail("你的内力不够，无法施展「飞花逐月」。");
    msg = HIY "$N五指分张，纵身跃起，使出一招[飞花逐月],顿时风云变色，天地间突然出现无数指头，向$n打去。\n";

    me->add_busy(4);
    //C-或者D-
    if ( target->query("combat_exp")/me->query("combat_exp")>=2 )
        rate_level=12;
    else
        rate_level=9;
     if(target->query_temp("special_skill/agile")>1)
	{
		agile_wt=(int)(target->query_temp("special_skill/agile")/5);
		rate_level += agile_wt;
	}


    if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), rate_level, me, target) ) {
            msg += HIR"结果$p被$P攻了个措手不及！\n" NOR;
            // target->set_temp("last_damage_from", me);
            message_vision(msg, me, target);
            // target->unconcious();
            yizhaoyun(target, me);
            me->add("neili",-500);
    } else {
            msg += HIW"可是$p还是躲过了$P的最后一击！！\n" NOR;
            message_vision(msg, me, target);
            me->add("neili",-2500);
    }
    return 1;
}
